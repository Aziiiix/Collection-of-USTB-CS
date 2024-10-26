#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int ans[4]={0,0,0,0};
	char lake[5][100];
	for(int hz=1;hz<=4;hz++)
	{
		for(int th=1;th<=4;th++)
		{
			if(hz==th)continue;
			for(int dt=1;dt<=4;dt++)
			{
				if(dt==hz||dt==th)continue;
				int by=10-hz-th-dt;
				
				ans[0]=(1==hz)+(4==dt)+(2==by);
				ans[1]=(4==hz)+(1==dt)+(3==by)+(2==th);
				ans[2]=(1==hz)+(2==dt);
				ans[3]=(4==by)+(1==th)+(3==hz)+(2==dt);
				if(ans[0]==1&&ans[1]==1&&ans[2]==1&&ans[3]==1)
				{
					strcpy(lake[dt],"Dongting Lake");
					strcpy(lake[by],"Boyang Lake");
					strcpy(lake[th],"Tai Lake");
					strcpy(lake[hz],"Hongze Lake");
				}
			}
		}
	}
	
	for(int i=1;i<=4;i++)
	{
		cout<<lake[i]<<endl;
	}
	
	return 0;
}
