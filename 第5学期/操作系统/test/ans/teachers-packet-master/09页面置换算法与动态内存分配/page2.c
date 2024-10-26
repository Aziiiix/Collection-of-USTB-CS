//最近一次访问次序
//参数j:  页面在内存块中的位置
//参数i： 页面号在页面号引用串中的位置
int DistanceLru(int *BlockofMemory, int *PageNumofRef, int j, int i)
{
	int k;
	for(k = i-1; k > 0; k--)
		if(BlockofMemory[j] == PageNumofRef[k])
		{
			return i-k;
		}
	return i;
}

//最近最久未使用页面置换算法
void Lru(int *BlockofMemory, int *PageNumofRef, int BlockCount, int PageNumRefCount)
{
	int i, j, k;
	int MinIndex1, MinIndex2;
	int MissCount = 0;
	int ReplacePage;
	int EmptyBlockCount = BlockCount;

	printf("************最近最久未使用页面置换算法：************\n");
	
	//输出页面引用串号
	OutputPageNumofRef(PageNumofRef, PageNumRefCount);

	for(i = 0; i < PageNumRefCount; i++)
	{
		if(!PageInBlockofMemory(PageNumofRef[i], BlockofMemory, BlockCount)) //页不在内存中
		{
			MissCount++;

			if(EmptyBlockCount > 0)
			{
				BlockofMemory[BlockCount - EmptyBlockCount] = PageNumofRef[i];
				OutputBlockofMemory(BlockofMemory, BlockCount, -1, PageNumofRef[i]);
				EmptyBlockCount--;
			}
			else
			{
				MinIndex1 = MinIndex2 = 0;
				//求出最近最久未被访问的页
				for(j = 0; j < BlockCount; j++)
				{
					MinIndex2 = DistanceLru(BlockofMemory, PageNumofRef, j, i);
					if(MinIndex1 < MinIndex2)
					{
						MinIndex1 = MinIndex2;
						k = j;
					}
				}
				ReplacePage = BlockofMemory[k];
				BlockofMemory[k] = PageNumofRef[i];
				OutputBlockofMemory(BlockofMemory, BlockCount, ReplacePage, PageNumofRef[i]);
			}
		}
		else
			OutputBlockofMemory(BlockofMemory, BlockCount, -1, PageNumofRef[i]);
	}

	printf("缺页次数为：%d\n", MissCount);
	printf("LRU缺页率为：%.3f\n", (float)MissCount / PageNumRefCount);
}
