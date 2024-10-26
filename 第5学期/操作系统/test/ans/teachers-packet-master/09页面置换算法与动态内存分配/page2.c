//���һ�η��ʴ���
//����j:  ҳ�����ڴ���е�λ��
//����i�� ҳ�����ҳ������ô��е�λ��
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

//������δʹ��ҳ���û��㷨
void Lru(int *BlockofMemory, int *PageNumofRef, int BlockCount, int PageNumRefCount)
{
	int i, j, k;
	int MinIndex1, MinIndex2;
	int MissCount = 0;
	int ReplacePage;
	int EmptyBlockCount = BlockCount;

	printf("************������δʹ��ҳ���û��㷨��************\n");
	
	//���ҳ�����ô���
	OutputPageNumofRef(PageNumofRef, PageNumRefCount);

	for(i = 0; i < PageNumRefCount; i++)
	{
		if(!PageInBlockofMemory(PageNumofRef[i], BlockofMemory, BlockCount)) //ҳ�����ڴ���
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
				//���������δ�����ʵ�ҳ
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

	printf("ȱҳ����Ϊ��%d\n", MissCount);
	printf("LRUȱҳ��Ϊ��%.3f\n", (float)MissCount / PageNumRefCount);
}
