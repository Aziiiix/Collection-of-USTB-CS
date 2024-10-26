/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
*/


/*
������ĺ�����ʵ���� SCAN ���̵����㷨�������㷨����
���㷨���ȿ��Ǵ�ͷ�ƶ��ķ���Ȼ���ٿ����ƶ�������̡�
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
	// ��һ�α�����ͬʱ�ҵ������������ƶ�������̵��̣߳����󣩡�
	//
	for (pListEntry = RequestListHead.Next;	// ��������еĵ�һ������������ͷָ�����һ������
	     pListEntry != &RequestListHead;	// �������������ͷʱ����ѭ����
	     pListEntry = pListEntry->Next) {
	
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
	return pNextRequest;
}
