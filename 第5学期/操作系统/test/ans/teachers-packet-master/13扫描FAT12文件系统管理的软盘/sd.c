/*
提供该示例代码是为了阐释一个概念，或者进行一个测试，并不代表着
最安全的编码实践，因此不应在应用程序或网站中使用该示例代码。对
于超出本示例代码的预期用途以外的使用所造成的偶然或继发性损失，
北京英真时代科技有限公司不承担任何责任。
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
	
	IntState = KeEnableInterrupts(FALSE);	// 关中断
	
	//
	// 得到 FAT12 文件系统设备对象，然后得到卷控制块 VCB
	//
	FatDevice = (PDEVICE_OBJECT)ObpLookupObjectByName(IopDeviceObjectType, "A:");
	pVcb = (PVCB)FatDevice->DeviceExtension;
	
	//
	// 将卷控制块中缓存的 BIOS Parameter Block (BPB) ，以及卷控制块中的其它重要信息输出
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
	// 扫描 FAT 表，统计空闲簇的数量，并计算软盘空间的使用情况
	//
	FreeClusterCount = 0;
	for (i = 2; i < pVcb->NumberOfClusters + 2; i++) {
		if (0 == FatGetFatEntryValue(pVcb, i))
			FreeClusterCount++;
	}
	UsedClusterCount = pVcb->NumberOfClusters - FreeClusterCount;
	fprintf(StdHandle, "Free Cluster Count: %d (%d Byte)\n", FreeClusterCount, FreeClusterCount*pVcb->Bpb.SectorsPerCluster*pVcb->Bpb.BytesPerSector);
	fprintf(StdHandle, "Used Cluster Count: %d (%d Byte)\n", UsedClusterCount, UsedClusterCount*pVcb->Bpb.SectorsPerCluster*pVcb->Bpb.BytesPerSector);
	
	KeEnableInterrupts(IntState);	// 开中断
}
