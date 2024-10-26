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
	USHORT Cluster;
	USHORT PrevCluster;
	ULONG FirstSectorOfCluster;
	ULONG OffsetInSector;
	ULONG BytesToWriteInSector;
	ULONG i, n;

	*BytesWriten = 0;

	if (Offset > File->FileSize) {	
		return STATUS_SUCCESS;
	}

	// 顺着文件簇链表向后移动，找到偏移位置所在的簇。
	PrevCluster = 0;
	Cluster = File->FirstCluster;
	for (i = Offset / FatBytesPerCluster(&Vcb->Bpb); i > 0; i--) {
		PrevCluster = Cluster;
		Cluster = FatGetFatEntryValue(Vcb, Cluster);	
	}

	// 从偏移位置所在的簇开始向后写文件。
	for (n = 0;;) {

		if (0 == Cluster || Cluster >= 0x0FF8) {

			// 簇链表结束，为文件分配一个空闲簇，将簇插入文件簇链表的尾部。
			Status = FatAllocateOneCluster(Vcb, &Cluster);
			if (!EOS_SUCCESS(Status)) {
				return Status;
			}

			if (0 == PrevCluster) {

				// 目前文件占用的磁盘空间为 0，簇链表为空，将簇直接设为表头。
				File->FirstCluster = Cluster;

			} else {

				// 将簇插入链表的尾部，如果插入失败则释放簇。
				Status = FatSetFatEntryValue(Vcb, PrevCluster, Cluster);
				if (!EOS_SUCCESS(Status)) {
					FatSetFatEntryValue(Vcb, Cluster, 0);
					return Status;
				}
			}
		}

		// 簇由多个连续扇区组成，计算簇的起始扇区号。
		FirstSectorOfCluster = Vcb->FirstDataSector + (Cluster - 2) * Vcb->Bpb.SectorsPerCluster;

		// 计算偏移位置在簇内的第几个扇区，然后从这个扇区开始向簇内的连续扇区写数据。
		for (i = ((Offset + n) / Vcb->Bpb.BytesPerSector) % Vcb->Bpb.SectorsPerCluster;
			i < Vcb->Bpb.SectorsPerCluster; i++) {

			// 计算写位置在扇区内的字节偏移。
			OffsetInSector = (Offset + n) % Vcb->Bpb.BytesPerSector;

			// 计算应该向这个扇区写的字节数。
			if (BytesToWrite - n > Vcb->Bpb.BytesPerSector - OffsetInSector) {
				BytesToWriteInSector = Vcb->Bpb.BytesPerSector - OffsetInSector;
			} else {
				BytesToWriteInSector = BytesToWrite - n; // 最后一个扇区
			}

			// 向扇区内写数据。
			Status = IopReadWriteSector( Vcb->DiskDevice,
										 FirstSectorOfCluster + i,
										 OffsetInSector,
										 (PCHAR)Buffer + n,
										 BytesToWriteInSector,
										 FALSE );

			if (!EOS_SUCCESS(Status)) {
				return Status;
			}

			n += BytesToWriteInSector;

			// 如果文件长度增加了则修改文件长度。
			if (Offset + n > File->FileSize) {
				File->FileSize = Offset + n;

				// 如果是数据文件则需要同步修改文件在磁盘上对应的 DIRENT 结构
				// 体。目录文件的 DIRENT 结构体中的 FileSize 永远为 0，无需修改。
				if (!File->AttrDirectory) {

					Status = FatWriteDirEntry(Vcb, File);
					if (!EOS_SUCCESS(Status)) {
						return Status;
					}
				}
			}

			*BytesWriten = n;
			if (n == BytesToWrite) {
				return STATUS_SUCCESS;
			}
		}

		// 继续向文件的下一个簇写数据。
		PrevCluster = Cluster;
		Cluster = FatGetFatEntryValue(Vcb, Cluster);
	}
}
