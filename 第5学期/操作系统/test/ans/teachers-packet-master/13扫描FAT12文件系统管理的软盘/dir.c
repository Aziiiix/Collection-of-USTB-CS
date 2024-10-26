/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
*/



PRIVATE
VOID
ConsoleCmdDir(
	IN HANDLE StdHandle
	)
{
	BOOL IntState;
	PDEVICE_OBJECT FatDevice;
	PVCB pVcb;
	PVOID pBuffer;
	SIZE_T BufferSize;
	PDIRENT pDirEntry;
	CHAR FileName[13];
	
	ULONG i, j, RootDirSectors, SpaceSize;
	
	IntState = KeEnableInterrupts(FALSE);	// ���ж�
	
	//
	// �õ� FAT12 �ļ�ϵͳ�豸����Ȼ��õ�����ƿ� VCB
	//
	FatDevice = (PDEVICE_OBJECT)ObpLookupObjectByName(IopDeviceObjectType, "A:");
	pVcb = (PVCB)FatDevice->DeviceExtension;
	
	//
	// ����һ�������ڴ���Ϊ��������Ȼ��������Ŀ¼�������̶��뻺������
	//
	pBuffer = NULL;		// ��ָ���������ĵ�ַ����ϵͳ�����������ĵ�ַ��
	BufferSize = pVcb->RootDirSize;	// ����Ļ�������С���Ŀ¼����С��ͬ��
	MmAllocateVirtualMemory(&pBuffer, &BufferSize, MEM_RESERVE | MEM_COMMIT, TRUE);
	
	RootDirSectors = pVcb->RootDirSize / pVcb->Bpb.BytesPerSector;	// �����Ŀ¼��ռ�õ���������
	for(i=0; i<RootDirSectors; i++) {
		
		// ����Ŀ¼��ռ�õ��������뻺����
		IopReadWriteSector( pVcb->DiskDevice,
							pVcb->FirstRootDirSector + i,
							0,
							(PCHAR)pBuffer + pVcb->Bpb.BytesPerSector * i,
							pVcb->Bpb.BytesPerSector,
							TRUE);
	}
	
	//
	// ɨ�軺�����еĸ�Ŀ¼������Ŀ¼�е��ļ����ļ�����Ϣ
	//
	fprintf(StdHandle, "Name        |   Size(Byte) |    Last Write Time   |   Space(Byte)\n");
	for(i=0; i<pVcb->Bpb.RootEntries; i++) {
	
		pDirEntry = (PDIRENT)(pBuffer + 32 * i);
		
		//
		// ����δʹ�õ�Ŀ¼��ͱ�ɾ����Ŀ¼��
		//
		if(0x0 == pDirEntry->Name[0]
			|| (CHAR)0xE5 == pDirEntry->Name[0])
			continue;
		
		FatConvertDirNameToFileName(pDirEntry->Name, FileName);
		
		//
		// ���ļ��ĵ�һ���ؿ�ʼ�����ļ�ռ�õ����дأ�ͳ���ļ�ռ�õĴ��̿ռ�
		//
		SpaceSize = 0;
		for (j = pDirEntry->FirstCluster; j != 0 && j != 0xFF8; ) {
			j = FatGetFatEntryValue(pVcb, j);
			SpaceSize += pVcb->Bpb.BytesPerSector * pVcb->Bpb.SectorsPerCluster;
		}
		
		fprintf(StdHandle, "%s        %d         %d-%d-%d %d:%d:%d         %d\n",
			FileName, pDirEntry->FileSize, 1980 + pDirEntry->LastWriteDate.Year,
			pDirEntry->LastWriteDate.Month, pDirEntry->LastWriteDate.Day,
			pDirEntry->LastWriteTime.Hour, pDirEntry->LastWriteTime.Minute,
			pDirEntry->LastWriteTime.DoubleSeconds, SpaceSize);
	}
	
	//
	// �ͷŻ�����
	//
	BufferSize = 0;	// ��������С����Ϊ 0����ʾ�ͷ�ȫ��������
	MmFreeVirtualMemory(&pBuffer, &BufferSize, MEM_RELEASE, TRUE);
	
	KeEnableInterrupts(IntState);	// ���ж�
}
