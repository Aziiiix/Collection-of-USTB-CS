/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
*/



PRIVATE
VOID
ConsoleCmdScanDisk(
	IN HANDLE StdHandle
	)
{
	BOOL IntState;
	PDEVICE_OBJECT FatDevice;
	PVCB pVcb;
	ULONG i, FreeClusterCount, UsedClusterCount;
	
	IntState = KeEnableInterrupts(FALSE);	// ���ж�
	
	//
	// �õ� FAT12 �ļ�ϵͳ�豸����Ȼ��õ�����ƿ� VCB
	//
	FatDevice = (PDEVICE_OBJECT)ObpLookupObjectByName(IopDeviceObjectType, "A:");
	pVcb = (PVCB)FatDevice->DeviceExtension;
	
	//
	// ������ƿ��л���� BIOS Parameter Block (BPB) ���Լ�����ƿ��е�������Ҫ��Ϣ���
	//
	fprintf(StdHandle, "******** BIOS Parameter Block (BPB) ********\n");
	fprintf(StdHandle, "Bytes Per Sector   : %d\n", pVcb->Bpb.BytesPerSector);
	fprintf(StdHandle, "Sectors Per Cluster: %d\n", pVcb->Bpb.SectorsPerCluster);
	fprintf(StdHandle, "Reserved Sectors   : %d\n", pVcb->Bpb.ReservedSectors);
	fprintf(StdHandle, "Fats               : %d\n", pVcb->Bpb.Fats);
	fprintf(StdHandle, "Root Entries       : %d\n", pVcb->Bpb.RootEntries);
	fprintf(StdHandle, "Sectors            : %d\n", pVcb->Bpb.Sectors);
	fprintf(StdHandle, "Media              : 0x%X\n", pVcb->Bpb.Media);
	fprintf(StdHandle, "Sectors Per Fat    : %d\n", pVcb->Bpb.SectorsPerFat);
	fprintf(StdHandle, "Sectors Per Track  : %d\n", pVcb->Bpb.SectorsPerTrack);
	fprintf(StdHandle, "Heads              : %d\n", pVcb->Bpb.Heads);
	fprintf(StdHandle, "Hidden Sectors     : %d\n", pVcb->Bpb.HiddenSectors);
	fprintf(StdHandle, "Large Sectors      : %d\n", pVcb->Bpb.LargeSectors);
	fprintf(StdHandle, "******** BIOS Parameter Block (BPB) ********\n\n");
	
	fprintf(StdHandle, "First Sector of Root Directroy: %d\n", pVcb->Bpb.ReservedSectors + pVcb->Bpb.Fats * pVcb->Bpb.SectorsPerFat);
	fprintf(StdHandle, "Size of Root Directroy        : %d\n", pVcb->Bpb.RootEntries * 32);
	fprintf(StdHandle, "First Sector of Data Area     : %d\n", pVcb->Bpb.ReservedSectors + pVcb->Bpb.Fats * pVcb->Bpb.SectorsPerFat + pVcb->Bpb.RootEntries * 32 / pVcb->Bpb.BytesPerSector);
	fprintf(StdHandle, "Number Of Clusters            : %d\n\n", (pVcb->Bpb.Sectors - (pVcb->Bpb.ReservedSectors + pVcb->Bpb.Fats * pVcb->Bpb.SectorsPerFat + pVcb->Bpb.RootEntries * 32 / pVcb->Bpb.BytesPerSector)) / pVcb->Bpb.SectorsPerCluster);
	
	//
	// ɨ�� FAT ��ͳ�ƿ��дص����������������̿ռ��ʹ�����
	//
	FreeClusterCount = 0;
	for (i = 2; i < pVcb->NumberOfClusters + 2; i++) {
		if (0 == FatGetFatEntryValue(pVcb, i))
			FreeClusterCount++;
	}
	UsedClusterCount = pVcb->NumberOfClusters - FreeClusterCount;
	fprintf(StdHandle, "Free Cluster Count: %d (%d Byte)\n", FreeClusterCount, FreeClusterCount*pVcb->Bpb.SectorsPerCluster*pVcb->Bpb.BytesPerSector);
	fprintf(StdHandle, "Used Cluster Count: %d (%d Byte)\n", UsedClusterCount, UsedClusterCount*pVcb->Bpb.SectorsPerCluster*pVcb->Bpb.BytesPerSector);
	
	KeEnableInterrupts(IntState);	// ���ж�
}
