/*
提供该示例代码是为了阐释一个概念，或者进行一个测试，并不代表着
最安全的编码实践，因此不应在应用程序或网站中使用该示例代码。对
于超出本示例代码的预期用途以外的使用所造成的偶然或继发性损失，
北京英真时代科技有限公司不承担任何责任。
*/


STATUS
PsResumThread(
	IN HANDLE hThread
	)
/*++

功能描述：
	恢复指定的线程。

参数：
	hThread - 需要被恢复的线程的句柄。

返回值：
	如果成功则返回 STATUS_SUCCESS。

--*/
{
	STATUS Status;
	BOOL IntState;
	PTHREAD Thread;

	//
	// 根据线程句柄获得线程对象的指针
	//
	Status = ObRefObjectByHandle(hThread, PspThreadType, (PVOID*)&Thread);

	if (EOS_SUCCESS(Status)) {

		IntState = KeEnableInterrupts(FALSE);	// 关中断

		if (Zero == Thread->State) {

			//
			// 将线程从挂起线程队列中移除。
			//
			ListRemoveEntry(&Thread->StateListEntry);
			
			//
			// 将挂起的线程恢复为就绪状态。
			// 线程由静止就绪状态（Static Ready）进入活动就绪状态（Active Ready）。
			//
			PspReadyThread(Thread);
			
			//
			// 执行线程调度，让刚刚恢复的线程有机会执行（如果真的能够调度到它的话）。
			//
			PspThreadSchedule();
			
			Status = STATUS_SUCCESS;
			
		} else {
		
			Status = STATUS_NOT_SUPPORTED;
			
		}

		KeEnableInterrupts(IntState);	// 开中断

		ObDerefObject(Thread);
	}

	return Status;
}
