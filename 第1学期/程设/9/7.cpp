#include<iostream>
using namespace std;
int main()
{
	int  m,n,p,q;
	cin>>m>>n;
	p=0;q=0;
	for(int i=1;i<m;i++){
		if(m%i==0)p=p+i;continue;
	}
	for(int i=1;i<n;i++){
		if(n%i==0)q=q+i;continue;
	}
	if(p==n&&m==q)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
