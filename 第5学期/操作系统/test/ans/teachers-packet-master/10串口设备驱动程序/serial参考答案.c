/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
*/


STATUS
SrlRead(
	IN PDEVICE_OBJECT DeviceObject,
	IN PFILE_OBJECT FileObject,
	OUT PVOID Buffer,
	IN ULONG Request,
	OUT PULONG Result OPTIONAL
	)
{
	BOOL IntState;
	ULONG Count = 0;
	PSERIAL_DEVICE_EXTENSION Ext = (PSERIAL_DEVICE_EXTENSION)DeviceObject->DeviceExtension;

	//
	// ������ջ�����Ϊ���������ȴ���ֱ�����ջ�������Ϊ�ǿա�
	//
	PsWaitForEvent(&Ext->RecvBufferNotEmpty, INFINITE);

	//
	// �����ջ�����������������������������ý��ջ������ǿ��¼�Ϊ��Ч��
	// ע�⣬����Խ��ջ������Ĳ������ܻ�ͽ����жϴ�������ͻ��
	// ����Ҫ�ر��жϡ�
	//
	IntState = KeEnableInterrupts(FALSE);

	Count = IopReadRingBuffer(Ext->RecvBuffer, Buffer, Request);

	if (IopIsRingBufferEmpty(Ext->RecvBuffer)) {
		PsResetEvent(&Ext->RecvBufferNotEmpty);
	}

	KeEnableInterrupts(IntState);

	*Result = Count;
	return STATUS_SUCCESS;
}
