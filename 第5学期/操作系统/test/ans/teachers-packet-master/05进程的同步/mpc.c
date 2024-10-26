/*
提供该示例代码是为了阐释一个概念，或者进行一个测试，并不代表着
最安全的编码实践，因此不应在应用程序或网站中使用该示例代码。对
于超出本示例代码的预期用途以外的使用所造成的偶然或继发性损失，
北京英真时代科技有限公司不承担任何责任。
*/

#include "EOSApp.h"

//
// 产品总数。
//
#define PRODUCT_COUNT	30

//
// 缓冲池。是生产者和消费者之间的临界资源。
//
#define BUFFER_SIZE		10
int Buffer[BUFFER_SIZE];

//
// 生产者使用的游标。是生产者之间的临界资源。
// 消费者使用的游标。是消费者之间的临界资源。
//
int InIndex = 0, OutIndex = 0;

//
// 已生产的产品数量。是生产者之间的临界资源。
// 已消费的产品数量。是消费者之间的临界资源。
//
int InCount = 0, OutCount = 0;

//
// 生产者线程数量，消费者线程数量。
//
#define PRODUCER_COUNT	10
#define CONSUMER_COUNT	7

//
// 用于生产者和消费者同步的对象句柄。
//
HANDLE MutexHandle;
HANDLE EmptySemaphoreHandle;
HANDLE FullSemaphoreHandle;

//
// 用于生产者之间的互斥体。保证只有一个生产者试图生产产品。
//
HANDLE ProducerMutexHandle;

//
// 用于消费者之间的互斥体。保证只有一个消费者试图消费产品。
//
HANDLE ConsumerMutexHandle;

//
// 生产者和消费者的线程函数
//
ULONG Producer(PVOID Param);
ULONG Consumer(PVOID Param);

//
// main 函数参数的意义：
// argc - argv 数组的长度，大小至少为 1，argc - 1 为命令行参数的数量。
// argv - 字符串指针数组，数组长度为命令行参数个数 + 1。其中 argv[0] 固定指向当前
//        进程所执行的可执行文件的路径字符串，argv[1] 及其后面的指针指向各个命令行
//        参数。
//        例如通过命令行内容 "a:\hello.exe -a -b" 启动进程后，hello.exe 的 main 函
//        数的参数 argc 的值为 3，argv[0] 指向字符串 "a:\hello.exe"，argv[1] 指向
//        参数字符串 "-a"，argv[2] 指向参数字符串 "-b"。
//
int main(int argc, char* argv[])
{
	//
	// 启动调试 EOS 应用程序前要特别注意下面的问题：
	//
	// 1、如果要在调试应用程序时能够调试进入内核并显示对应的源码，
	//    必须使用 EOS 核心项目编译生成完全版本的 SDK 文件夹，然
	//    后使用此文件夹覆盖应用程序项目中的 SDK 文件夹，并且 EOS
	//    核心项目在磁盘上的位置不能改变。
	//
	
	HANDLE ProducerHandleArray[PRODUCER_COUNT];
	HANDLE ConsumerHandleArray[CONSUMER_COUNT];
	
	INT i;
	
	//
	// 创建用于互斥访问缓冲池临界资源的 Mutex 对象。
	//
	MutexHandle = CreateMutex(FALSE, NULL);
	if (NULL == MutexHandle) {
		return 1;
	}
	
	//
	// 创建生产者之间、消费者之间互斥的 Mutex 对象。
	//
	ProducerMutexHandle = CreateMutex(FALSE, NULL);
	if (NULL == ProducerMutexHandle) {
		return 1;
	}
	ConsumerMutexHandle = CreateMutex(FALSE, NULL);
	if (NULL == ConsumerMutexHandle) {
		return 1;
	}

	//
	// 创建 Empty 信号量，表示缓冲池中空缓冲区数量。初始计数和最大计数都为 BUFFER_SIZE。
	//
	EmptySemaphoreHandle = CreateSemaphore(BUFFER_SIZE, BUFFER_SIZE, NULL);
	if (NULL == EmptySemaphoreHandle) {
		return 2;
	}

	//
	// 创建 Full 信号量，表示缓冲池中满缓冲区数量。初始计数为 0，最大计数为 BUFFER_SIZE。
	//
	FullSemaphoreHandle = CreateSemaphore(0, BUFFER_SIZE, NULL);
	if (NULL == FullSemaphoreHandle) {
		return 3;
	}

	//
	// 创建所有生产者线程。
	//
	for(i=0; i<PRODUCER_COUNT; i++) {
	
		ProducerHandleArray[i] = CreateThread( 0,		// 默认堆栈大小
								   			Producer,	// 线程函数入口地址
								   			(PVOID)i+1,	// 线程函数参数
								   			0,			// 创建标志
								   			NULL );		// 线程 ID
		
		if (NULL == ProducerHandleArray[i]) {
			return 4;
		}
	}

	//
	// 创建所有消费者线程。
	//
	for(i=0; i<CONSUMER_COUNT; i++) {
	
		ConsumerHandleArray[i] = CreateThread( 0,		// 默认堆栈大小
								   			Consumer,	// 线程函数入口地址
								   			(PVOID)i+1,	// 线程函数参数
								   			0,			// 创建标志
								   			NULL );		// 线程 ID
		
		if (NULL == ConsumerHandleArray[i]) {
			return 5;
		}
	}

	//
	// 等待所有生产者线程结束。
	//
	for(i=0; i<PRODUCER_COUNT; i++) {
	
		WaitForSingleObject(ProducerHandleArray[i], INFINITE);
		CloseHandle(ProducerHandleArray[i]);
	}
	
	//
	// 等待所有消费者线程结束。
	//
	for(i=0; i<CONSUMER_COUNT; i++) {
	
		WaitForSingleObject(ConsumerHandleArray[i], INFINITE);
		CloseHandle(ConsumerHandleArray[i]);
	}
	
	//
	// 关闭同步对象句柄
	//
	CloseHandle(MutexHandle);
	CloseHandle(ProducerMutexHandle);
	CloseHandle(ConsumerMutexHandle);
	CloseHandle(EmptySemaphoreHandle);
	CloseHandle(FullSemaphoreHandle);

	return 0;
}

//
// 生产者线程函数。参数为线程编号。
//
ULONG Producer(PVOID Param) 
{
	while(TRUE) {
	
		//
		// 进入生产者临界区
		//
		WaitForSingleObject(ProducerMutexHandle, INFINITE);
		
		//
		// 如果生产的产品数量还不足，就生产一个产品。
		//
		if(InCount < PRODUCT_COUNT) {
		
			WaitForSingleObject(EmptySemaphoreHandle, INFINITE);
			WaitForSingleObject(MutexHandle, INFINITE);
	
			Buffer[InIndex] = InCount;
			printf("#%d Produce a %d at %d\n", (INT)Param, InCount, InIndex);
	
			ReleaseMutex(MutexHandle);
			ReleaseSemaphore(FullSemaphoreHandle, 1, NULL);
			
			InCount++;
			InIndex = (InIndex + 1) % BUFFER_SIZE;
	
			//
			// 休息一会。每 500 毫秒生产一个数。
			//
			Sleep(500);
		}
		
		//
		// 退出生产者临界区
		//
		ReleaseMutex(ProducerMutexHandle);
		
		//
		// 如果已经生产了所有的产品，就结束。
		//
		if(InCount >= PRODUCT_COUNT)
			break;
	}
	
	return 0;
}

//
// 消费者线程函数。参数为线程编号。
//
ULONG Consumer(PVOID Param)
{
	while(TRUE) {
	
		//
		// 进入消费者临界区
		//
		WaitForSingleObject(ConsumerMutexHandle, INFINITE);
		
		//
		// 如果消费的产品数量还不足，就消费一个产品。
		//
		if(OutCount < PRODUCT_COUNT) {
		
			WaitForSingleObject(FullSemaphoreHandle, INFINITE);
			WaitForSingleObject(MutexHandle, INFINITE);
	
			printf("\t\t\t#%d Consume a %d at %d\n", (INT)Param, Buffer[OutIndex], OutIndex);
				
			ReleaseMutex(MutexHandle);
			ReleaseSemaphore(EmptySemaphoreHandle, 1, NULL);
			
			OutCount++;
			OutIndex = (OutIndex + 1) % BUFFER_SIZE;
	
			//
			// 休息一会儿。让前 10 个数的消费速度比较慢，后面的较快。
			//
			if (OutCount <= 10) {
				Sleep(2000);
			} else {
				Sleep(100);
			}
		}
		
		//
		// 退出消费者临界区
		//
		ReleaseMutex(ConsumerMutexHandle);
		
		//
		// 如果已经消费了所有的产品，就结束。
		//
		if(OutCount >= PRODUCT_COUNT)
			break;
	}
	
	return 0;
}
