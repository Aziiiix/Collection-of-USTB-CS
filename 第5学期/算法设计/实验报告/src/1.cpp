#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,b;
	cin>>n>>b;
	vector<int> h(n);
	for (int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	sort(h.begin(),h.end());
	reverse(h.begin(),h.end());
	int con=0,sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=h[i];
		con++;
		if(sum>=b)
		{
			break;
		}
	}
	cout<<con<<endl;
	
	return 0;
 } 
