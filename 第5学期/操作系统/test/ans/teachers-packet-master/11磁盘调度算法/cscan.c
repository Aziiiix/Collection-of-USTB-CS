/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
*/


/*
������ĺ�����ʵ���� CSCAN ���̵����㷨��
SCAN �㷨���ԸĽ�Ϊ CSCAN �㷨������� CSCAN �㷨�涨��ͷֻ��
���������ƶ�������ͷ�ƶ������ڵı����ʴŵ�ʱ����ͷ�����ƶ���
����ı����ʴŵ����������ŵ��Ž�������С�ŵ��Ź���ѭ������
��ɨ�衣
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
	ULONG OutsideLongestDistance = 0x0;
	PREQUEST pNextRequest;
	PREQUEST pNextRequestInside = NULL;
	PREQUEST pNextRequestOutside = NULL;
	
	//
	// ��һ�α�����ͬʱ�ҵ������ƶ�������̵ĺ������ƶ���������̣߳����󣩡�
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
		} else if (Offset < 0 && -Offset > OutsideLongestDistance) {
			//
			// ��¼�����ƶ���������߳�
			//
			OutsideLongestDistance = -Offset;
			pNextRequestOutside = pRequest;
		}
	}
	
	//
	// ѡ�������ƶ�������̵��̣߳����û�������ƶ����̣߳�
	// ��ѡ�������ƶ���������̣߳����´�������ɨ�衣
	//
	pNextRequest = pNextRequestInside != NULL ? pNextRequestInside : pNextRequestOutside;
	
RETURN:
	return pNextRequest;
}
