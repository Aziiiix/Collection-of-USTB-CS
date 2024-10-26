/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
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

	// ˳���ļ�����������ƶ����ҵ�ƫ��λ�����ڵĴء�
	PrevCluster = 0;
	Cluster = File->FirstCluster;
	for (i = Offset / FatBytesPerCluster(&Vcb->Bpb); i > 0; i--) {
		PrevCluster = Cluster;
		Cluster = FatGetFatEntryValue(Vcb, Cluster);	
	}

	// ��ƫ��λ�����ڵĴؿ�ʼ���д�ļ���
	for (n = 0;;) {

		if (0 == Cluster || Cluster >= 0x0FF8) {

			// �����������Ϊ�ļ�����һ�����дأ����ز����ļ��������β����
			Status = FatAllocateOneCluster(Vcb, &Cluster);
			if (!EOS_SUCCESS(Status)) {
				return Status;
			}

			if (0 == PrevCluster) {

				// Ŀǰ�ļ�ռ�õĴ��̿ռ�Ϊ 0��������Ϊ�գ�����ֱ����Ϊ��ͷ��
				File->FirstCluster = Cluster;

			} else {

				// ���ز��������β�����������ʧ�����ͷŴء�
				Status = FatSetFatEntryValue(Vcb, PrevCluster, Cluster);
				if (!EOS_SUCCESS(Status)) {
					FatSetFatEntryValue(Vcb, Cluster, 0);
					return Status;
				}
			}
		}

		// ���ɶ������������ɣ�����ص���ʼ�����š�
		FirstSectorOfCluster = Vcb->FirstDataSector + (Cluster - 2) * Vcb->Bpb.SectorsPerCluster;

		// ����ƫ��λ���ڴ��ڵĵڼ���������Ȼ������������ʼ����ڵ���������д���ݡ�
		for (i = ((Offset + n) / Vcb->Bpb.BytesPerSector) % Vcb->Bpb.SectorsPerCluster;
			i < Vcb->Bpb.SectorsPerCluster; i++) {

			// ����дλ���������ڵ��ֽ�ƫ�ơ�
			OffsetInSector = (Offset + n) % Vcb->Bpb.BytesPerSector;

			// ����Ӧ�����������д���ֽ�����
			if (BytesToWrite - n > Vcb->Bpb.BytesPerSector - OffsetInSector) {
				BytesToWriteInSector = Vcb->Bpb.BytesPerSector - OffsetInSector;
			} else {
				BytesToWriteInSector = BytesToWrite - n; // ���һ������
			}

			// ��������д���ݡ�
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

			// ����ļ��������������޸��ļ����ȡ�
			if (Offset + n > File->FileSize) {
				File->FileSize = Offset + n;

				// ����������ļ�����Ҫͬ���޸��ļ��ڴ����϶�Ӧ�� DIRENT �ṹ
				// �塣Ŀ¼�ļ��� DIRENT �ṹ���е� FileSize ��ԶΪ 0�������޸ġ�
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

		// �������ļ�����һ����д���ݡ�
		PrevCluster = Cluster;
		Cluster = FatGetFatEntryValue(Vcb, Cluster);
	}
}
