#include<iostream>
using namespace std;
int main()
{
    for(int a=123;a<329;a++)
    {
    	int b=2*a;
    	int c=3*a;
    	int num=a*1000000+b*1000+c;
    	bool s[10]={0};
    	while(num)
    	{
    		s[num%10]=1;
    		num/=10;
		}
		bool f=1;
		for(int i=1;i<=9;i++)
		{
			if(s[i]==0){
			f=0;break;}
		}
		if(f)cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}
