#include<iostream>
using namespace std;
int compute(int n,int k)
{
	if(n>=k){
		int p=1,q=1,z=1;
		for(int i=1;i<=n;++i){
			p*=i;
		}
		for(int i=1;i<=k;++i){
			q*=i;
		}
		for(int i=1;i<=(n-k);++i){
			z*=i;
		}
		return p/q/z;
	}
	else{
		return 0;
	}
}
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<compute(m,n);
	return 0;
}
