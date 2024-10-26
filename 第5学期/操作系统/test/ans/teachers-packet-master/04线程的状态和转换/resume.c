/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
*/


STATUS
PsResumThread(
	IN HANDLE hThread
	)
/*++

����������
	�ָ�ָ�����̡߳�

������
	hThread - ��Ҫ���ָ����̵߳ľ����

����ֵ��
	����ɹ��򷵻� STATUS_SUCCESS��

--*/
{
	STATUS Status;
	BOOL IntState;
	PTHREAD Thread;

	//
	// �����߳̾������̶߳����ָ��
	//
	Status = ObRefObjectByHandle(hThread, PspThreadType, (PVOID*)&Thread);

	if (EOS_SUCCESS(Status)) {

		IntState = KeEnableInterrupts(FALSE);	// ���ж�

		if (Zero == Thread->State) {

			//
			// ���̴߳ӹ����̶߳������Ƴ���
			//
			ListRemoveEntry(&Thread->StateListEntry);
			
			//
			// ��������ָ̻߳�Ϊ����״̬��
			// �߳��ɾ�ֹ����״̬��Static Ready����������״̬��Active Ready����
			//
			PspReadyThread(Thread);
			
			//
			// ִ���̵߳��ȣ��øոջָ����߳��л���ִ�У��������ܹ����ȵ����Ļ�����
			//
			PspThreadSchedule();
			
			Status = STATUS_SUCCESS;
			
		} else {
		
			Status = STATUS_NOT_SUPPORTED;
			
		}

		KeEnableInterrupts(IntState);	// ���ж�

		ObDerefObject(Thread);
	}

	return Status;
}
