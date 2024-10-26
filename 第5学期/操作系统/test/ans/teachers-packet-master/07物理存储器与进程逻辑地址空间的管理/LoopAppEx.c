#include "EOSApp.h"

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
	
	//
	// ����һ�����ͱ�������Ŀռ�
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
	// �޸����ͱ�����ֵ
	//
	printf("Virtual memory original value: 0x%X\n", *pValue);
	*pValue = 0xFFFFFFFF;
	printf("Virtual memory new value: 0x%X\n\n", *pValue);
	
	//
	// �ȴ� 10 ����
	//
	INT Second = 10;
	printf("Wait for %d second\n\n", Second);
	Sleep(Second * 1000);
	
	//
	// �ͷſռ�
	//
	if(!VirtualFree((PVOID)pValue, 0, MEM_RELEASE)) {
		printf("Release virtual memory failed!\n\n");
	} else {
		printf("Release virtual memory success!\n\n");
	}
	
	//
	// ��ʼ��ѭ��������Ӧ�ó�����̾Ͳ��������
	//
	printf("Endless loop!\n");
	for(;;) {
	}

	return 0;
}
