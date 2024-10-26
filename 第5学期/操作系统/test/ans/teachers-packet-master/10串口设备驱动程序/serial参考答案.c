/*
提供该示例代码是为了阐释一个概念，或者进行一个测试，并不代表着
最安全的编码实践，因此不应在应用程序或网站中使用该示例代码。对
于超出本示例代码的预期用途以外的使用所造成的偶然或继发性损失，
北京英真时代科技有限公司不承担任何责任。
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
	// 如果接收缓冲区为空则阻塞等待，直到接收缓冲区变为非空。
	//
	PsWaitForEvent(&Ext->RecvBufferNotEmpty, INFINITE);

	//
	// 读接收缓冲区，如果缓冲区被读空则还需设置接收缓冲区非空事件为无效。
	// 注意，下面对接收缓冲区的操作可能会和接收中断处理程序冲突，
	// 所以要关闭中断。
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
