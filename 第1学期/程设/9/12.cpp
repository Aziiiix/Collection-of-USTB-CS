#include <iostream>
#include <cstring>

using namespace std;


#define maxn 1010    //����һ���Ա�1000�������
 
int a[maxn];
 
int main()
{
	int n, k, first = 1;       //n յ�ƣ�k ����
	memset(a, 0, sizeof(a));   //��a��Ԫ����Ϊ0
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= k; i++)     //��i��ʾ
		for(int j = 1; j <=n; j++)
			if(j % i == 0)
				a[j] = !a[j];
	for (int i = 1; i <= n; i++)
	{
	        if(a[i]){
			if(first)
				first = 0;
			else
				printf(" ");
			printf("%d",i);
		}
	}
	printf("\n");
 
	return 0;
}
