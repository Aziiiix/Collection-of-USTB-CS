#include<iostream>
using namespace std;
int a[100]={363,201,4,416,404,433,305,213,212,480,3,247,196,372,366,107,322,510,559,136,7,158,331,209,23,130,406,405};
int f(int a,int b)
{
	int c=(a+b)/2;
	if(a<0) return 0;
	if(a>=b) return a[b];
	else if (f(a,c>f(c+1,b))) return f(a,c);
	else return f(c+1,b);
 } 
 
 int main()
 {
 	for(int i=-5;i<70;i++)
 	{
 		for(int j=-5;j<55;i++)
 		{
 			if(f(i,j)==342)
 			if(f(i-1,j)!=342 || i<=0)
 			if(f(i,j+1)!=342 || j>43)
 			
 			cout<<i<<" "<<j<<endl;
		 }
	 }
 }
