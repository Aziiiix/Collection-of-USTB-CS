#include<iostream>
using namespace std;

int a[2005],i,n,x,p,k,j; 
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x;
		p=-1;
		for(j=1;j<=k;j++){
			if(a[j]>=x){
				p=j; 
				break;
			}
		}
		if(p==-1){
			k++;
			a[k]=x;
		}else{
			a[p]=x;
		}
	}
	
	cout<<k;
}
