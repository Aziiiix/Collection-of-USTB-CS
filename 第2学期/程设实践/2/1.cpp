#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char* Ori=new char [10001];
	char* Son=new char [10001];
	cin>>Ori>>Son;
	int m=strlen(Ori),n=strlen(Son);
	int num=0;
	
	for(int i=0;i<m;i++)
	{
		if(Ori[i]==Son[0])
		{
			int j=i,p=0;
			for(j<m;p<n;p++)
			{
				if(p==n-1)
				{
					if(Ori[j]==Son[p]){num++;break;}
					else{break;} 
				}
				else
				{
					if(Ori[j]==Son[p]){j++;}
					else{break;}
				}
			}
		}
	}
	cout<<num;
	return 0; 
}
