/*
提供该示例代码是为了阐释一个概念，或者进行一个测试，并不代表着
最安全的编码实践，因此不应在应用程序或网站中使用该示例代码。对
于超出本示例代码的预期用途以外的使用所造成的偶然或继发性损失，
北京英真时代科技有限公司不承担任何责任。
*/


/*
在下面的函数中实现了 SCAN 磁盘调度算法（电梯算法）。
该算法优先考虑磁头移动的方向，然后再考虑移动距离最短。
*/


PREQUEST
IopDiskSchedule(
	VOID
	)
{
	PLIST_ENTRY pListEntry;
	PREQUEST pRequest;
	LONG Offset;
	
	ULONG InsideShortestDistance = 0xFFFFFFFF;
	ULONG OutsideShortestDistance = 0xFFFFFFFF;
	PREQUEST pNextRequest;
	PREQUEST pNextRequestInside = NULL;
	PREQUEST pNextRequestOutside = NULL;
	
	//
	// 在一次遍历中同时找到两个方向上移动距离最短的线程（请求）。
	//
	for (pListEntry = RequestListHead.Next;	// 请求队列中的第一个请求是链表头指向的下一个请求。
	     pListEntry != &RequestListHead;	// 遍历到请求队列头时结束循环。
	     pListEntry = pListEntry->Next) {
	
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
	return pNextRequest;
}
