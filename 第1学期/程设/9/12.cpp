#include <iostream>
#include <cstring>

using namespace std;


#define maxn 1010    //定义一个稍比1000大的数组
 
int a[maxn];
 
int main()
{
	int n, k, first = 1;       //n 盏灯，k 个人
	memset(a, 0, sizeof(a));   //把a中元素置为0
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= k; i++)     //用i表示
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
