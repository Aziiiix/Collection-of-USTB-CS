#include<iostream>
#define MAX 1000
int main(){
	int x,temp,sum;
	for(x=1;x<=MAX;x++){
		sum=0;
		for(temp=1;temp<x;temp++){
			if(x%temp==0)
			sum=sum+temp;
		}
		if(sum==x)
		printf("%d ",x);
	}
	return 0;
} 
