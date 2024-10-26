#include<stdio.h>
#define MAX 1000
int main(void){
	int x,temp,sum;
	for(x=1;x<=MAX;x++){
		sum=0;
		for(temp=1;temp<x;temp++){
			if(x%temp==0)
			sum=sum+temp;
		}
		if(sum==x)
		printf("%d\t",x);
	}
	putchar('\n');
	fflush(stdin);
	return 0;
} 
