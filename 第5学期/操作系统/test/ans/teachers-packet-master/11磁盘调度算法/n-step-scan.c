/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
*/


/*
������ĺ�����ʵ���� N-Step-CSCAN ���̵����㷨��
N-Step-SCAN �㷨������������зֳ����ɸ�����Ϊ N ���Ӷ��У�����
���Ƚ��� FCFS �㷨���δ�����Щ�Ӷ��С���ÿ����һ���Ӷ���ʱ����
�ǰ� SCAN �㷨����һ���Ӷ��д�������ٴ��������Ӷ��С�
*/


PREQUEST
IopDiskSchedule(
	VOID
	)
{
	//
	// ��һ���Ӷ���ʣ��ĳ���
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
	// ֻ�����Ӷ��У���һ�α�����ͬʱ�ҵ������������ƶ�������̵��̣߳����󣩡�
	//
	for (pListEntry = RequestListHead.Next;	// �Ӷ����еĵ�һ������������ͷָ�����һ������
	     SubQueueLenght > 0 && pListEntry != &RequestListHead;	// �������Ӷ���βʱ����ѭ����
	     SubQueueLenght--, pListEntry = pListEntry->Next) {
	
		//
		// �����������������ָ��
		//
		pRequest = CONTAINING_RECORD(pListEntry, REQUEST, ListEntry);
		
		//
		// ���������Ӧ���߳������ʵĴŵ��뵱ǰ��ͷ���ڴŵ���ƫ�ƣ�������������ʾ��
		//
		Offset = pRequest->Cylinder - CurrentCylinder;
		
		if (0 == Offset) {
			//
			// ����߳�Ҫ���ʵĴŵ��뵱ǰ��ͷ���ڴŵ���ͬ�����������ء�
			//
			pNextRequest = pRequest;
			goto RETURN;
		} else if (Offset > 0 && Offset < InsideShortestDistance) {
			//
			// ��¼�����ƶ�������̵��߳�
			//
			InsideShortestDistance = Offset;
			pNextRequestInside = pRequest;
		} else if (Offset < 0 && -Offset < OutsideShortestDistance) {
			//
			// ��¼�����ƶ�������̵��߳�
			//
			OutsideShortestDistance = -Offset;
			pNextRequestOutside = pRequest;
		}
	}
	
	if (ScanInside) {
		//
		// ��ͷ�����ƶ�ʱ��ѡ�������ƶ�������̵��̣߳����û�������ƶ����̣߳�
		// ��ת������ѡ�������ƶ�������̵��̡߳�
		//
		pNextRequest = pNextRequestInside != NULL ? pNextRequestInside : pNextRequestOutside;
		ScanInside =  pNextRequestInside != NULL ? ScanInside : !ScanInside;
	} else {
		//
		// ��ͷ�����ƶ�ʱ��ѡ�������ƶ�������̵��̣߳����û�������ƶ����̣߳�
		// ��ת������ѡ�������ƶ�������̵��̡߳�
		//
		pNextRequest = pNextRequestOutside != NULL ? pNextRequestOutside : pNextRequestInside;
		ScanInside =  pNextRequestOutside != NULL ? ScanInside : !ScanInside;			
	}
	
RETURN:
	//
	// ����һ���Ӷ���ʣ��ĳ��ȼ��� 1�������һ���Ӷ��г��ȱ�Ϊ 0��˵����һ��
	// �Ӷ��д�����ϣ����Ӷ���ʣ��ĳ������±�Ϊ N����ʼ������һ���Ӷ��У�
	// ��ʱ����һ���Ӷ��оͱ�Ϊ�˵�һ���Ӷ��С�
	//
	SubQueueRemainLength--;
	if (0 == SubQueueRemainLength)
		SubQueueRemainLength = SUB_QUEUE_LENGTH;
	
	return pNextRequest;
}
