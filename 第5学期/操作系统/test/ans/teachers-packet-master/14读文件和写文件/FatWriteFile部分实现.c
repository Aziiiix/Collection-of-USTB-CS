/*
提供该示例代码是为了阐释一个概念，或者进行一个测试，并不代表着
最安全的编码实践，因此不应在应用程序或网站中使用该示例代码。对
于超出本示例代码的预期用途以外的使用所造成的偶然或继发性损失，
北京英真时代科技有限公司不承担任何责任。
*/


STATUS
FatWriteFile(
	IN PVCB Vcb,
	IN PFCB File,
	IN ULONG Offset,
	IN ULONG BytesToWrite,
	OUT PVOID Buffer,
	OUT PULONG BytesWriten
	)
{
	STATUS Status;

	// 由于在将新分配的簇插入簇链尾部时，必须知道前一个簇的簇号，
	// 所以定义了“前一个簇号”和“当前簇号”两个变量。
	USHORT PrevClusterNum, CurrentClusterNum;
	USHORT NextClusterNum;
	USHORT NewClusterNum;
	ULONG ClusterIndex;
	ULONG FirstSectorOfCluster;
	ULONG BytesToWriteInCurSector;
	ULONG OffsetInSector;
	
	ULONG i;

	// 写入的起始位置不能超出文件大小（并不影响增加文件大小或增加簇，想想原因？）
	if (Offset > File->FileSize) {
		return STATUS_SUCCESS;
	}

	// 根据簇的大小，计算写入的起始位置在簇链的第几个簇中（从 0 开始计数）
	ClusterIndex = Offset / FatBytesPerCluster(&Vcb->Bpb);
	
	// 顺着簇链向后查找写入的起始位置所在簇的簇号。
	PrevClusterNum = 0;
	CurrentClusterNum = File->FirstCluster;
	for (i = ClusterIndex; i > 0; i--) {
		PrevClusterNum = CurrentClusterNum;
		CurrentClusterNum = FatGetFatEntryValue(Vcb, PrevClusterNum);	
	}

	// 如果写入的起始位置还没有对应的簇，就增加簇
	if (0 == CurrentClusterNum || CurrentClusterNum >= 0xFF8) {

		// 为文件分配一个空闲簇
		FatAllocateOneCluster(Vcb, &NewClusterNum);

		// 将新分配的簇安装到簇链中。		
		if (0 == File->FirstCluster)
			File->FirstCluster = NewClusterNum;
		else
			FatSetFatEntryValue(Vcb, PrevClusterNum, NewClusterNum);
		
		CurrentClusterNum = NewClusterNum;
	}
	
	// 计算写位置在扇区内的字节偏移。
	OffsetInSector = Offset % Vcb->Bpb.BytesPerSector;
	
	// 先假设所有的数据都写入当前扇区
	BytesToWriteInCurSector = BytesToWrite;
	
	// 如果写入的数据跨越扇区边界
	if(OffsetInSector + BytesToWrite > Vcb->Bpb.BytesPerSector) {
	
		// 根据当前簇号得到下一个簇号
		NextClusterNum = FatGetFatEntryValue(Vcb, CurrentClusterNum);
		
		// 已经是文件末尾，需要分配新簇，并将新簇链接到簇链末尾
		if(NextClusterNum >= 0xFF8) {
		
			FatAllocateOneCluster(Vcb, &NewClusterNum);
			FatSetFatEntryValue(Vcb, CurrentClusterNum, NewClusterNum);
			NextClusterNum = NewClusterNum;
		}
		
		// 计算下一个簇的第一个扇区的扇区号。
		FirstSectorOfCluster = Vcb->FirstDataSector + (NextClusterNum - 2) * Vcb->Bpb.SectorsPerCluster;
		
		IopReadWriteSector( Vcb->DiskDevice,
							FirstSectorOfCluster,
							0,
							(PCHAR)Buffer - OffsetInSector + Vcb->Bpb.BytesPerSector,
							BytesToWrite - Vcb->Bpb.BytesPerSector + OffsetInSector,
							FALSE );
		
		if (!EOS_SUCCESS(Status))
			return Status;
		
		// 重新计算要写入当前扇区的字节数量
		BytesToWriteInCurSector = Vcb->Bpb.BytesPerSector - OffsetInSector;
	}
	
	// 计算当前簇的第一个扇区的扇区号。
	FirstSectorOfCluster = Vcb->FirstDataSector + (CurrentClusterNum - 2) * Vcb->Bpb.SectorsPerCluster;

	Status = IopReadWriteSector( Vcb->DiskDevice,
									FirstSectorOfCluster,
									OffsetInSector,
									(PCHAR)Buffer,
									BytesToWriteInCurSector,
									FALSE );

	if (!EOS_SUCCESS(Status))
		return Status;

	// 如果文件长度增加了则修改文件长度。
	if (Offset + BytesToWrite > File->FileSize) {
		File->FileSize = Offset + BytesToWrite;
		
		// 如果是数据文件则需要同步修改文件在磁盘上对应的 DIRENT 结构
		// 体。目录文件的 DIRENT 结构体中的 FileSize 永远为 0，无需修改。
		if (!File->AttrDirectory)
			FatWriteDirEntry(Vcb, File);
	}
	
	// 返回实际写入的字节数量
	*BytesWriten = BytesToWrite;

	return STATUS_SUCCESS;
}
