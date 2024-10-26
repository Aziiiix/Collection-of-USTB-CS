/*
提供该示例代码是为了阐释一个概念，或者进行一个测试，并不代表着
最安全的编码实践，因此不应在应用程序或网站中使用该示例代码。对
于超出本示例代码的预期用途以外的使用所造成的偶然或继发性损失，
北京英真时代科技有限公司不承担任何责任。
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

	IntState = KeEnableInterrupts(FALSE);	// 关中断
	
	// *((PINT)0xE0000000) = 100;	// 访问未映射物理内存的虚拟地址会触发异常。
	
	ULONG PfnArray[2];
	
	//
	// 从内核申请两个未用的物理页。
	// 由 PfnArray 数组返回两个物理页的页框号。
	//
	MiAllocateZeroedPages(2, PfnArray);
	OutputFormat = "New page frame number: 0x%X, 0x%X\n";
	fprintf(StdHandle, OutputFormat, PfnArray[0], PfnArray[1]);
	KdbPrint(OutputFormat, PfnArray[0], PfnArray[1]);
	
	//
	// 使用 PfnArray[0] 页做为页表，映射基址为 0xE00000000 的 4M 虚拟地址。
	//
	IndexOfDirEntry = (0xE0000000 >> 22);	// 虚拟地址的高 10 位是 PDE 标号
	((PMMPTE_HARDWARE)0xC0300000)[IndexOfDirEntry].PageFrameNumber = PfnArray[0];
	((PMMPTE_HARDWARE)0xC0300000)[IndexOfDirEntry].Valid = 1;		// 有效
	((PMMPTE_HARDWARE)0xC0300000)[IndexOfDirEntry].Writable = 1;	// 可写
	MiFlushEntireTlb();	// 刷新快表
	
	//
	// 根据 PDE 的标号计算其映射的页表所在虚拟地址的基址
	//
	PageTableBase = 0xC0000000 + IndexOfDirEntry * PAGE_SIZE;
	
	//
	// 将 PfnArray[1] 放入页表 PfnArray[0] 的两个 PTE 中，
	// 分别映射基址为 0xE0000000 和 0xE0001000 的 4K 虚拟地址
	//
	IndexOfTableEntry = (0xE0000000 >> 12) & 0x3FF;	// 虚拟地址的 12-22 位是 PTE 标号
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].PageFrameNumber = PfnArray[1];
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Valid = 1;		// 有效
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Writable = 1;	// 可写
	MiFlushEntireTlb();	// 刷新快表
	
	IndexOfTableEntry = (0xE0001000 >> 12) & 0x3FF;	// 虚拟地址的 12-22 位是 PTE 标号
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].PageFrameNumber = PfnArray[1];
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Valid = 1;		// 有效
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Writable = 1;	// 可写
	MiFlushEntireTlb();	// 刷新快表
	
	//
	// 测试
	//
	OutputFormat = "Read Memory 0xE0001000: %d\n";
	fprintf(StdHandle, OutputFormat, *((PINT)0xE0001000));
	KdbPrint(OutputFormat, *((PINT)0xE0001000));
	*((PINT)0xE0000000) = 100;	// 写共享内存
	fprintf(StdHandle, OutputFormat, *((PINT)0xE0001000));
	KdbPrint(OutputFormat, *((PINT)0xE0001000));
	
	//
	// 输出页目录的页框号
	//
	OutputFormat = "\nCR3->0x%X\n";
	PfnOfPageDirectory = (ULONG)(PspSystemProcess->Pas->PfnOfPageDirectory);
	fprintf(StdHandle, OutputFormat, PfnOfPageDirectory);
	KdbPrint(OutputFormat, PfnOfPageDirectory);

	//
	// 遍历页目录中的 PDE
	//
	for(IndexOfDirEntry = 0; IndexOfDirEntry < PTE_PER_TABLE; IndexOfDirEntry++)
	{
		pPde = (PMMPTE_HARDWARE)((ULONG_PTR)PDE_BASE + IndexOfDirEntry * PTE_SIZE);

		//
		// 跳过无效的 PDE
		//
		if(!pPde->Valid)
			continue;

		//
		// 输出 PDE 信息，格式如下：
		// PDE: 标号 (映射的 4M 虚拟地址的基址)->所映射页表的页框号
		//
		OutputFormat = "PDE: 0x%X (0x%X)->0x%X\n";
		VirtualBase = (IndexOfDirEntry << PDI_SHIFT);
		fprintf(StdHandle, OutputFormat, IndexOfDirEntry, VirtualBase, pPde->PageFrameNumber);
		KdbPrint(OutputFormat, IndexOfDirEntry, VirtualBase, pPde->PageFrameNumber);

		//
		// 根据 PDE 的标号计算其映射的页表所在虚拟地址的基址
		//
		PageTableBase = (ULONG_PTR)PTE_BASE + IndexOfDirEntry * PAGE_SIZE;

		//
		// 遍历页表中的 PTE
		//
		for(IndexOfTableEntry = 0; IndexOfTableEntry < PTE_PER_TABLE; IndexOfTableEntry++)
		{
			pPte = (PMMPTE_HARDWARE)(PageTableBase + IndexOfTableEntry * PTE_SIZE);

			//
			// 跳过无效的 PTE
			//
			if(!pPte->Valid)
				continue;

			//
			// 输出 PTE 信息，格式如下：
			// PTE: 标号 (映射的 4K 虚拟地址的基址)->所映射物理页的页框号
			//
			OutputFormat = "\t\tPTE: 0x%X (0x%X)->0x%X\n";
			VirtualBase = (IndexOfDirEntry << PDI_SHIFT) | (IndexOfTableEntry << PTI_SHIFT);
			fprintf(StdHandle, OutputFormat, IndexOfTableEntry, VirtualBase, pPte->PageFrameNumber);
			KdbPrint(OutputFormat, IndexOfTableEntry, VirtualBase, pPte->PageFrameNumber);

			//
			// 统计占用的物理页数
			//
			PageTotal++;
		}
	}

	//
	// 输出占用的物理页数，和物理内存数
	//
	OutputFormat = "\nPhysical Page Total: %d\n";
	fprintf(StdHandle, OutputFormat, PageTotal);
	KdbPrint(OutputFormat, PageTotal);
	OutputFormat = "Physical Memory Total: %d\n\n";
	fprintf(StdHandle, OutputFormat, PageTotal * PAGE_SIZE);
	KdbPrint(OutputFormat, PageTotal * PAGE_SIZE);
	
	//
	// 输出释放物理页前的未用物理页数量
	//
	OutputFormat = "\nNonused Page Count: %d\n";
	fprintf(StdHandle, OutputFormat, MiGetAnyPageCount());
	KdbPrint(OutputFormat, MiGetAnyPageCount());
	
	//
	// 从 PTE 中移除物理页
	//
	IndexOfDirEntry = (0xE0000000 >> 22);	// 虚拟地址的高 10 位是 PDE 标号
	PageTableBase = 0xC0000000 + IndexOfDirEntry * PAGE_SIZE;
	
	IndexOfTableEntry = (0xE0000000 >> 12) & 0x3FF;	// 虚拟地址的 12-22 位是 PTE 标号
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Valid = 0;
	
	IndexOfTableEntry = (0xE0001000 >> 12) & 0x3FF;	// 虚拟地址的 12-22 位是 PTE 标号
	((PMMPTE_HARDWARE)PageTableBase)[IndexOfTableEntry].Valid = 0;
	
	//
	// 从 PDE 中移除物理页
	//
	((PMMPTE_HARDWARE)0xC0300000)[IndexOfDirEntry].Valid = 0;

	//
	// 刷新快表
	//
	MiFlushEntireTlb();
	
	//
	// 释放物理页
	//
	MiFreePages(2, PfnArray);
	
	//
	// 输出释放物理页后的未用物理页数量，验证释放成功
	//
	OutputFormat = "\nNonused Page Count: %d\n";
	fprintf(StdHandle, OutputFormat, MiGetAnyPageCount());
	KdbPrint(OutputFormat, MiGetAnyPageCount());

	KeEnableInterrupts(IntState);	// 开中断
}
