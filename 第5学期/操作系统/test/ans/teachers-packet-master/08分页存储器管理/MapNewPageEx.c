/*
�ṩ��ʾ��������Ϊ�˲���һ��������߽���һ�����ԣ�����������
�ȫ�ı���ʵ������˲�Ӧ��Ӧ�ó������վ��ʹ�ø�ʾ�����롣��
�ڳ�����ʾ�������Ԥ����;�����ʹ������ɵ�żȻ��̷�����ʧ��
����Ӣ��ʱ���Ƽ����޹�˾���е��κ����Ρ�
*/

PRIVATE
VOID
ConsoleCmdMemoryMap(
	IN HANDLE StdHandle
	)
{
	BOOL IntState;

	ULONG PfnOfPageDirectory;
	ULONG PageTotal = 0;
	ULONG IndexOfDirEntry;
	ULONG IndexOfTableEntry;
	PMMPTE_HARDWARE pPde;
	PMMPTE_HARDWARE pPte;
	ULONG_PTR PageTableBase;
	ULONG_PTR VirtualBase;

	const char* OutputFormat = NULL;
	

	ASSERT(PspCurrentProcess == PspSystemProcess);

	IntState = KeEnableInterrupts(FALSE);	// ���ж�
	
	// *((PINT)0xE0000000) = 100;	// ����δӳ�������ڴ�������ַ�ᴥ���쳣��
	
	ULONG PfnArray[2];
	
	//
	// ���ں���������δ�õ�����ҳ��
	// �� PfnArray ���鷵����������ҳ��ҳ��š�
	//
	MiAllocateZeroedPages(2, PfnArray);
	OutputFormat = "New page frame number: 0x%X, 0x%X\n";
	fprintf(StdHandle, OutputFormat, PfnArray[0], PfnArray[1]);
	KdbPrint(OutputFormat, PfnArray[0], PfnArray[1]);
	
	//
	// ʹ�� PfnArray[0] ҳ��Ϊҳ��ӳ���ַΪ 0xE00000000 �� 4M �����ַ��
	//
	IndexOfDirEntry = (0xE0000000 >> 22);	// �����ַ�ĸ� 10 λ�� PDE ���
	((PMMPTE_HARDWARE)0xC0300000)[IndexOfDirEntry].PageFrameNumber = PfnArray[0];
	((PMMPTE_HARDWARE)0xC0300000)[IndexOfDirEntry].Valid = 1;		// ��Ч
	((PMMPTE_HARDWARE)0xC0300000)[IndexOfDirEntry].Writable = 1;	// ��д
	MiFlushEntireTlb();	// ˢ�¿��
	
	//
	// ���� PDE �ı�ż�����ӳ���ҳ�����������ַ�Ļ�ַ
	//
	PageTableBase = 0xC0000000 + IndexOfDirEntry * PAGE_SIZE;
	
	//
	// �� PfnArray[1] ����ҳ�� PfnArray[0] ������ PTE �У�
	// �ֱ�ӳ���ַΪ 0xE0000000 �� 0xE0001000 �� 4K �����ַ
	//
	IndexOfTableEntry = (0xE0000000 >> 12) & 0x3FF;	// �����ַ�� 12-22 λ�� PTE ���
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].PageFrameNumber = PfnArray[1];
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Valid = 1;		// ��Ч
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Writable = 1;	// ��д
	MiFlushEntireTlb();	// ˢ�¿��
	
	IndexOfTableEntry = (0xE0001000 >> 12) & 0x3FF;	// �����ַ�� 12-22 λ�� PTE ���
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].PageFrameNumber = PfnArray[1];
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Valid = 1;		// ��Ч
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Writable = 1;	// ��д
	MiFlushEntireTlb();	// ˢ�¿��
	
	//
	// ����
	//
	OutputFormat = "Read Memory 0xE0001000: %d\n";
	fprintf(StdHandle, OutputFormat, *((PINT)0xE0001000));
	KdbPrint(OutputFormat, *((PINT)0xE0001000));
	*((PINT)0xE0000000) = 100;	// д�����ڴ�
	fprintf(StdHandle, OutputFormat, *((PINT)0xE0001000));
	KdbPrint(OutputFormat, *((PINT)0xE0001000));
	
	//
	// ���ҳĿ¼��ҳ���
	//
	OutputFormat = "\nCR3->0x%X\n";
	PfnOfPageDirectory = (ULONG)(PspSystemProcess->Pas->PfnOfPageDirectory);
	fprintf(StdHandle, OutputFormat, PfnOfPageDirectory);
	KdbPrint(OutputFormat, PfnOfPageDirectory);

	//
	// ����ҳĿ¼�е� PDE
	//
	for(IndexOfDirEntry = 0; IndexOfDirEntry < PTE_PER_TABLE; IndexOfDirEntry++)
	{
		pPde = (PMMPTE_HARDWARE)((ULONG_PTR)PDE_BASE + IndexOfDirEntry * PTE_SIZE);

		//
		// ������Ч�� PDE
		//
		if(!pPde->Valid)
			continue;

		//
		// ��� PDE ��Ϣ����ʽ���£�
		// PDE: ��� (ӳ��� 4M �����ַ�Ļ�ַ)->��ӳ��ҳ���ҳ���
		//
		OutputFormat = "PDE: 0x%X (0x%X)->0x%X\n";
		VirtualBase = (IndexOfDirEntry << PDI_SHIFT);
		fprintf(StdHandle, OutputFormat, IndexOfDirEntry, VirtualBase, pPde->PageFrameNumber);
		KdbPrint(OutputFormat, IndexOfDirEntry, VirtualBase, pPde->PageFrameNumber);

		//
		// ���� PDE �ı�ż�����ӳ���ҳ�����������ַ�Ļ�ַ
		//
		PageTableBase = (ULONG_PTR)PTE_BASE + IndexOfDirEntry * PAGE_SIZE;

		//
		// ����ҳ���е� PTE
		//
		for(IndexOfTableEntry = 0; IndexOfTableEntry < PTE_PER_TABLE; IndexOfTableEntry++)
		{
			pPte = (PMMPTE_HARDWARE)(PageTableBase + IndexOfTableEntry * PTE_SIZE);

			//
			// ������Ч�� PTE
			//
			if(!pPte->Valid)
				continue;

			//
			// ��� PTE ��Ϣ����ʽ���£�
			// PTE: ��� (ӳ��� 4K �����ַ�Ļ�ַ)->��ӳ������ҳ��ҳ���
			//
			OutputFormat = "\t\tPTE: 0x%X (0x%X)->0x%X\n";
			VirtualBase = (IndexOfDirEntry << PDI_SHIFT) | (IndexOfTableEntry << PTI_SHIFT);
			fprintf(StdHandle, OutputFormat, IndexOfTableEntry, VirtualBase, pPte->PageFrameNumber);
			KdbPrint(OutputFormat, IndexOfTableEntry, VirtualBase, pPte->PageFrameNumber);

			//
			// ͳ��ռ�õ�����ҳ��
			//
			PageTotal++;
		}
	}

	//
	// ���ռ�õ�����ҳ�����������ڴ���
	//
	OutputFormat = "\nPhysical Page Total: %d\n";
	fprintf(StdHandle, OutputFormat, PageTotal);
	KdbPrint(OutputFormat, PageTotal);
	OutputFormat = "Physical Memory Total: %d\n\n";
	fprintf(StdHandle, OutputFormat, PageTotal * PAGE_SIZE);
	KdbPrint(OutputFormat, PageTotal * PAGE_SIZE);
	
	//
	// ����ͷ�����ҳǰ��δ������ҳ����
	//
	OutputFormat = "\nNonused Page Count: %d\n";
	fprintf(StdHandle, OutputFormat, MiGetAnyPageCount());
	KdbPrint(OutputFormat, MiGetAnyPageCount());
	
	//
	// �� PTE ���Ƴ�����ҳ
	//
	IndexOfDirEntry = (0xE0000000 >> 22);	// �����ַ�ĸ� 10 λ�� PDE ���
	PageTableBase = 0xC0000000 + IndexOfDirEntry * PAGE_SIZE;
	
	IndexOfTableEntry = (0xE0000000 >> 12) & 0x3FF;	// �����ַ�� 12-22 λ�� PTE ���
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Valid = 0;
	
	IndexOfTableEntry = (0xE0001000 >> 12) & 0x3FF;	// �����ַ�� 12-22 λ�� PTE ���
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Valid = 0;
	
	//
	// �� PDE ���Ƴ�����ҳ
	//
	((PMMPTE_HARDWARE)0xC0300000)[IndexOfDirEntry].Valid = 0;

	//
	// ˢ�¿��
	//
	MiFlushEntireTlb();
	
	//
	// �ͷ�����ҳ
	//
	MiFreePages(2, PfnArray);
	
	//
	// ����ͷ�����ҳ���δ������ҳ��������֤�ͷųɹ�
	//
	OutputFormat = "\nNonused Page Count: %d\n";
	fprintf(StdHandle, OutputFormat, MiGetAnyPageCount());
	KdbPrint(OutputFormat, MiGetAnyPageCount());

	KeEnableInterrupts(IntState);	// ���ж�
}
