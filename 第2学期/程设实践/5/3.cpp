#include<iostream>
#include<algorithm>
using namespace std;

class Data
{
public:
	int banana, times;
	int number[105];
	Data() {}
	Data(int x, int y) { banana = x; times = y; }
};

int main()
{
	int num_group; cin >> num_group;
	Data* group = new Data[num_group];
	for (int i = 0; i < num_group; i++)
	{
		int pbanana, ptimes; cin >> pbanana >> ptimes;
		group[i].banana = pbanana; group[i].times = ptimes;
		for (int j = 1; j <= pbanana; j++)
		{
			cin >> group[i].number[j];
		}
		group[i].number[0] = 0; group[i].number[pbanana + 1] = 101;
	}
	
	for(int i=0;i<num_group;i++)
	{
		if(group[i].banana<=group[i].times)
		{
			cout<<"100"<<endl;continue;
		}
		int ans=0;
		int l=1,r=group[i].times;
		while(r<=group[i].banana)
		{
			ans=max(ans,group[i].number[r+1]-group[i].number[l-1]-1);
			l++;r++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
