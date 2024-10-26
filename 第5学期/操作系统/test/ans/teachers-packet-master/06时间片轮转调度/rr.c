/*
提供该示例代码是为了阐释一个概念，或者进行一个测试，并不代表着
最安全的编码实践，因此不应在应用程序或网站中使用该示例代码。对
于超出本示例代码的预期用途以外的使用所造成的偶然或继发性损失，
北京英真时代科技有限公司不承担任何责任。
*/

VOID
PspRoundRobin(
	VOID
	)
{
	//
	// 只有在当前线程（被中断线程）仍处于运行状态时，才进行时间片轮转调度。
	// 如果当前线程被阻塞，就不需要进行时间片轮转调度。
	//
	if (NULL != PspCurrentThread && Running == PspCurrentThread->State) {

		//
		// 将当前运行线程的剩余时间片减少 1。
		//
		PspCurrentThread->RemainderTicks--;
		
		//
		// 如果剩余时间片变为 0 则执行如下操作：
		// 1. 重新为当前线程分配时间片。
		// 2. 如果存在和当前线程优先级相同的就绪线程，就将当前线程转入就绪状态。
		//
		if (0 == PspCurrentThread->RemainderTicks) {

			PspCurrentThread->RemainderTicks = TICKS_OF_TIME_SLICE;

			if (BIT_TEST(PspReadyBitmap, PspCurrentThread->Priority)) {
			
				//
				// PspReadyThread 函数会将线程插入其优先级对应的就绪队列的队尾，
				// 并设置就绪位图中对应的位。最后将线程的状态修改为就绪状态。
				//
				PspReadyThread(PspCurrentThread);
			}
		}
	}
}
