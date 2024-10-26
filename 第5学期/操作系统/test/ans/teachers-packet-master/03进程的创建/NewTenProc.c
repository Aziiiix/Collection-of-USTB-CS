/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
*/

#include "EOSApp.h"

//
// �����ӽ��̵�������
// �޸Ĵ˺궨���ֵ�����Դ���ָ���������ӽ��̡�
//
#define PROC_COUNT 10	


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
	
	STARTUPINFO StartupInfo;	// �ӽ��̵�������Ϣ
	PROCESS_INFORMATION ProcInfoArray[PROC_COUNT];	// �ӽ�����Ϣ���飬����Ԫ�ص������봴���ӽ��̵�������ͬ
	ULONG ulExitCode;	// �ӽ��̵��˳���
	INT i;				// ѭ��������

	printf("Create %d processes and wait for the processes exit...\n\n", PROC_COUNT);

	//
	// ʹ�ӽ��̺͸�����ʹ����ͬ�ı�׼�����
	//
	StartupInfo.StdInput = GetStdHandle(STD_INPUT_HANDLE);
	StartupInfo.StdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	StartupInfo.StdError = GetStdHandle(STD_ERROR_HANDLE);

	//
	// Ϊһ��Ӧ�ó���ͬʱ��������ӽ��̡�
	//
	for(i=0; i<PROC_COUNT; i++) {
		
		if(!CreateProcess("A:\\Hello.exe", NULL, 0, &StartupInfo, &ProcInfoArray[i])) {
			
			// ��������ӽ���ʧ�ܣ����������Ϣ���˳���
			printf("CreateProcess Failed, Error code: 0x%X.\n", GetLastError());
			return 1;
		}
	}
	
	//
	// �ȴ������ӽ��̽�����
	//
	for(i=0; i<PROC_COUNT; i++) {
	
		WaitForSingleObject(ProcInfoArray[i].ProcessHandle, INFINITE);
	}
	
	//
	// ��������ӽ��̵��˳��룬���ر����в���ʹ�õľ����
	//
	for(i=0; i<PROC_COUNT; i++) {
	
		GetExitCodeProcess(ProcInfoArray[i].ProcessHandle, &ulExitCode);
		printf("Process %d exit with %d.\n", i+1, ulExitCode);
		
		CloseHandle(ProcInfoArray[i].ProcessHandle);
		CloseHandle(ProcInfoArray[i].ThreadHandle);
	}

	return 0;
}
