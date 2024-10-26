#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	int **x;
	x=new int*[m];
	for(int i=0;i<m;i++)
	{
		x[i]=new int[n];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>x[i][j];
		 } 
	}
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<m;i++)
		{
			if(i<m-1){
			cout<<x[i][j]<<" ";
		  }
		    if(i==m-1){
		    	cout<<x[i][j]<<endl;
			}
		 } 
	}
	return 0;
}
