/*
提供该示例代码是为了阐释一个概念，或者进行一个测试，并不代表着
最安全的编码实践，因此不应在应用程序或网站中使用该示例代码。对
于超出本示例代码的预期用途以外的使用所造成的偶然或继发性损失，
北京英真时代科技有限公司不承担任何责任。
*/


/*
在下面的函数中实现了 N-Step-CSCAN 磁盘调度算法。
N-Step-SCAN 算法将磁盘请求队列分成若干个长度为 N 的子队列，磁盘
调度将按 FCFS 算法依次处理这些子队列。而每处理一个子队列时，又
是按 SCAN 算法，对一个子队列处理完后再处理其它子队列。
*/


PREQUEST
IopDiskSchedule(
	VOID
	)
{
	//
	// 第一个子队列剩余的长度
	//
	ULONG SubQueueLenght = SubQueueRemainLength;
	
	PLIST_ENTRY pListEntry;
	PREQUEST pRequest;
	LONG Offset;
	
	ULONG InsideShortestDistance = 0xFFFFFFFF;
	ULONG OutsideShortestDistance = 0xFFFFFFFF;
	PREQUEST pNextRequest;
	PREQUEST pNextRequestInside = NULL;
	PREQUEST pNextRequestOutside = NULL;
	
	//
	// 只遍历子队列，在一次遍历中同时找到两个方向上移动距离最短的线程（请求）。
	//
	for (pListEntry = RequestListHead.Next;	// 子队列中的第一个请求是链表头指向的下一个请求。
	     SubQueueLenght > 0 && pListEntry != &RequestListHead;	// 遍历到子队列尾时结束循环。
	     SubQueueLenght--, pListEntry = pListEntry->Next) {
	
		//
		// 根据链表项获得请求的指针
		//
		pRequest = CONTAINING_RECORD(pListEntry, REQUEST, ListEntry);
		
		//
		// 计算请求对应的线程所访问的磁道与当前磁头所在磁道的偏移（方向由正负表示）
		//
		Offset = pRequest->Cylinder - CurrentCylinder;
		
		if (0 == Offset) {
			//
			// 如果线程要访问的磁道与当前磁头所在磁道相同，可立即返回。
			//
			pNextRequest = pRequest;
			goto RETURN;
		} else if (Offset > 0 && Offset < InsideShortestDistance) {
			//
			// 记录向内移动距离最短的线程
			//
			InsideShortestDistance = Offset;
			pNextRequestInside = pRequest;
		} else if (Offset < 0 && -Offset < OutsideShortestDistance) {
			//
			// 记录向外移动距离最短的线程
			//
			OutsideShortestDistance = -Offset;
			pNextRequestOutside = pRequest;
		}
	}
	
	if (ScanInside) {
		//
		// 磁头向内移动时，选择向内移动距离最短的线程，如果没有向内移动的线程，
		// 就转换方向，选择向外移动距离最短的线程。
		//
		pNextRequest = pNextRequestInside != NULL ? pNextRequestInside : pNextRequestOutside;
		ScanInside =  pNextRequestInside != NULL ? ScanInside : !ScanInside;
	} else {
		//
		// 磁头向外移动时，选择向外移动距离最短的线程，如果没有向外移动的线程，
		// 就转换方向，选择向内移动距离最短的线程。
		//
		pNextRequest = pNextRequestOutside != NULL ? pNextRequestOutside : pNextRequestInside;
		ScanInside =  pNextRequestOutside != NULL ? ScanInside : !ScanInside;			
	}
	
RETURN:
	//
	// 将第一个子队列剩余的长度减少 1。如果第一个子队列长度变为 0，说明第一个
	// 子队列处理完毕，将子队列剩余的长度重新变为 N，开始处理下一个子队列，
	// 此时，下一个子队列就变为了第一个子队列。
	//
	SubQueueRemainLength--;
	if (0 == SubQueueRemainLength)
		SubQueueRemainLength = SUB_QUEUE_LENGTH;
	
	return pNextRequest;
}
