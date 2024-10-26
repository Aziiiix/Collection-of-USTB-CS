#include<iostream>
using namespace std;
void cal_step(int n);
int main()
{
	int num;
	cin>>num;
	cal_step(num);
	return 0;
 }
void cal_step(int n)
{
	int i=0;
	for(n>1;n<1000000;)
	{
		if(n==1)break;
		if(n%2==0){
			n=n/2;cout<<n<<" ";i++;continue;
		}
		if(n%2==1){
			n=(3*n)+1;cout<<n<<" ";i++;continue;
		}
	}
	cout<<endl;
	cout<<i;
 }
