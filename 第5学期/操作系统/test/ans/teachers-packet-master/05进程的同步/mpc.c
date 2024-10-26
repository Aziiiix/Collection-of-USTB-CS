/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
*/

#include "EOSApp.h"

//
// ��Ʒ������
//
#define PRODUCT_COUNT	30

//
// ����ء��������ߺ�������֮����ٽ���Դ��
//
#define BUFFER_SIZE		10
int Buffer[BUFFER_SIZE];

//
// ������ʹ�õ��αꡣ��������֮����ٽ���Դ��
// ������ʹ�õ��αꡣ��������֮����ٽ���Դ��
//
int InIndex = 0, OutIndex = 0;

//
// �������Ĳ�Ʒ��������������֮����ٽ���Դ��
// �����ѵĲ�Ʒ��������������֮����ٽ���Դ��
//
int InCount = 0, OutCount = 0;

//
// �������߳��������������߳�������
//
#define PRODUCER_COUNT	10
#define CONSUMER_COUNT	7

//
// ���������ߺ�������ͬ���Ķ�������
//
HANDLE MutexHandle;
HANDLE EmptySemaphoreHandle;
HANDLE FullSemaphoreHandle;

//
// ����������֮��Ļ����塣��ֻ֤��һ����������ͼ������Ʒ��
//
HANDLE ProducerMutexHandle;

//
// ����������֮��Ļ����塣��ֻ֤��һ����������ͼ���Ѳ�Ʒ��
//
HANDLE ConsumerMutexHandle;

//
// �����ߺ������ߵ��̺߳���
//
ULONG Producer(PVOID Param);
ULONG Consumer(PVOID Param);

//
// main �������������壺
// argc - argv ����ĳ��ȣ���С����Ϊ 1��argc - 1 Ϊ�����в�����������
// argv - �ַ���ָ�����飬���鳤��Ϊ�����в������� + 1������ argv[0] �̶�ָ��ǰ
//        ������ִ�еĿ�ִ���ļ���·���ַ�����argv[1] ��������ָ��ָ�����������
//        ������
//        ����ͨ������������ "a:\hello.exe -a -b" �������̺�hello.exe �� main ��
//        ���Ĳ��� argc ��ֵΪ 3��argv[0] ָ���ַ��� "a:\hello.exe"��argv[1] ָ��
//        �����ַ��� "-a"��argv[2] ָ������ַ��� "-b"��
//
int main(int argc, char* argv[])
{
	//
	// �������� EOS Ӧ�ó���ǰҪ�ر�ע����������⣺
	//
	// 1�����Ҫ�ڵ���Ӧ�ó���ʱ�ܹ����Խ����ں˲���ʾ��Ӧ��Դ�룬
	//    ����ʹ�� EOS ������Ŀ����������ȫ�汾�� SDK �ļ��У�Ȼ
	//    ��ʹ�ô��ļ��и���Ӧ�ó�����Ŀ�е� SDK �ļ��У����� EOS
	//    ������Ŀ�ڴ����ϵ�λ�ò��ܸı䡣
	//
	
	HANDLE ProducerHandleArray[PRODUCER_COUNT];
	HANDLE ConsumerHandleArray[CONSUMER_COUNT];
	
	INT i;
	
	//
	// �������ڻ�����ʻ�����ٽ���Դ�� Mutex ����
	//
	MutexHandle = CreateMutex(FALSE, NULL);
	if (NULL == MutexHandle) {
		return 1;
	}
	
	//
	// ����������֮�䡢������֮�以��� Mutex ����
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
	// ���� Empty �ź�������ʾ������пջ�������������ʼ��������������Ϊ BUFFER_SIZE��
	//
	EmptySemaphoreHandle = CreateSemaphore(BUFFER_SIZE, BUFFER_SIZE, NULL);
	if (NULL == EmptySemaphoreHandle) {
		return 2;
	}

	//
	// ���� Full �ź�������ʾ�����������������������ʼ����Ϊ 0��������Ϊ BUFFER_SIZE��
	//
	FullSemaphoreHandle = CreateSemaphore(0, BUFFER_SIZE, NULL);
	if (NULL == FullSemaphoreHandle) {
		return 3;
	}

	//
	// ���������������̡߳�
	//
	for(i=0; i<PRODUCER_COUNT; i++) {
	
		ProducerHandleArray[i] = CreateThread( 0,		// Ĭ�϶�ջ��С
								   			Producer,	// �̺߳�����ڵ�ַ
								   			(PVOID)i+1,	// �̺߳�������
								   			0,			// ������־
								   			NULL );		// �߳� ID
		
		if (NULL == ProducerHandleArray[i]) {
			return 4;
		}
	}

	//
	// ���������������̡߳�
	//
	for(i=0; i<CONSUMER_COUNT; i++) {
	
		ConsumerHandleArray[i] = CreateThread( 0,		// Ĭ�϶�ջ��С
								   			Consumer,	// �̺߳�����ڵ�ַ
								   			(PVOID)i+1,	// �̺߳�������
								   			0,			// ������־
								   			NULL );		// �߳� ID
		
		if (NULL == ConsumerHandleArray[i]) {
			return 5;
		}
	}

	//
	// �ȴ������������߳̽�����
	//
	for(i=0; i<PRODUCER_COUNT; i++) {
	
		WaitForSingleObject(ProducerHandleArray[i], INFINITE);
		CloseHandle(ProducerHandleArray[i]);
	}
	
	//
	// �ȴ������������߳̽�����
	//
	for(i=0; i<CONSUMER_COUNT; i++) {
	
		WaitForSingleObject(ConsumerHandleArray[i], INFINITE);
		CloseHandle(ConsumerHandleArray[i]);
	}
	
	//
	// �ر�ͬ��������
	//
	CloseHandle(MutexHandle);
	CloseHandle(ProducerMutexHandle);
	CloseHandle(ConsumerMutexHandle);
	CloseHandle(EmptySemaphoreHandle);
	CloseHandle(FullSemaphoreHandle);

	return 0;
}

//
// �������̺߳���������Ϊ�̱߳�š�
//
ULONG Producer(PVOID Param) 
{
	while(TRUE) {
	
		//
		// �����������ٽ���
		//
		WaitForSingleObject(ProducerMutexHandle, INFINITE);
		
		//
		// ��������Ĳ�Ʒ���������㣬������һ����Ʒ��
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
			// ��Ϣһ�ᡣÿ 500 ��������һ������
			//
			Sleep(500);
		}
		
		//
		// �˳��������ٽ���
		//
		ReleaseMutex(ProducerMutexHandle);
		
		//
		// ����Ѿ����������еĲ�Ʒ���ͽ�����
		//
		if(InCount >= PRODUCT_COUNT)
			break;
	}
	
	return 0;
}

//
// �������̺߳���������Ϊ�̱߳�š�
//
ULONG Consumer(PVOID Param)
{
	while(TRUE) {
	
		//
		// �����������ٽ���
		//
		WaitForSingleObject(ConsumerMutexHandle, INFINITE);
		
		//
		// ������ѵĲ�Ʒ���������㣬������һ����Ʒ��
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
			// ��Ϣһ�������ǰ 10 �����������ٶȱȽ���������ĽϿ졣
			//
			if (OutCount <= 10) {
				Sleep(2000);
			} else {
				Sleep(100);
			}
		}
		
		//
		// �˳��������ٽ���
		//
		ReleaseMutex(ConsumerMutexHandle);
		
		//
		// ����Ѿ����������еĲ�Ʒ���ͽ�����
		//
		if(OutCount >= PRODUCT_COUNT)
			break;
	}
	
	return 0;
}
