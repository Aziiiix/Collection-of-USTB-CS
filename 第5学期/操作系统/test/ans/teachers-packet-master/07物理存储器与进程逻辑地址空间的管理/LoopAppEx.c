#include "EOSApp.h"

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
	
	//
	// 分配一个整型变量所需的空间
	//
	PINT pValue;
	SIZE_T Size = sizeof(PINT);
	pValue = (PINT)VirtualAlloc((PVOID)0, Size, MEM_RESERVE | MEM_COMMIT);
	if(NULL == pValue) {
		printf("Allocate virtual memory failed!\n\n");
		return;
	} else {
		printf("Allocate %d bytes virtual memory at 0x%X.\n\n", Size, pValue);
	}
	
	//
	// 修改整型变量的值
	//
	printf("Virtual memory original value: 0x%X\n", *pValue);
	*pValue = 0xFFFFFFFF;
	printf("Virtual memory new value: 0x%X\n\n", *pValue);
	
	//
	// 等待 10 秒钟
	//
	INT Second = 10;
	printf("Wait for %d second\n\n", Second);
	Sleep(Second * 1000);
	
	//
	// 释放空间
	//
	if(!VirtualFree((PVOID)pValue, 0, MEM_RELEASE)) {
		printf("Release virtual memory failed!\n\n");
	} else {
		printf("Release virtual memory success!\n\n");
	}
	
	//
	// 开始死循环，这样应用程序进程就不会结束。
	//
	printf("Endless loop!\n");
	for(;;) {
	}

	return 0;
}
