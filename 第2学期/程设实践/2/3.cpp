#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void Func(int *a,int len)
{
	sort(a,a+len);
	for(int i=len-1;i>=0;i--)
	{
		if(i==0){cout<<a[i]<<endl;}
		else{cout<<a[i]<<" ";}
	}
	for(int i=len-1;i>=0;i--)
	{
		if(a[i]==0)
		{
			cout<<len-i-1<<endl;
			break;
		}
	}
}

int main()
{
	char c;
	int num;
	vector<int> nums;
	int len=1;
	while (scanf("%d", &num) != EOF){
		nums.push_back(num);
		c = cin.get();
		if (c != ' ')
		{
			break;
		}
		len++;
	}

	int A[len];
	for(int i=0;i<len;i++)
	{
		A[i]=nums[i];
	}
	int *p=A;
	Func(p,len);
	
	return 0;
}
