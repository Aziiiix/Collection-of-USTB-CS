#include<iostream>
#include<cstring> 
#define inf 0x3f3f3f3f
using namespace std;
int n;
char arr[1005];
char brr[1005];
int e[30][30];
void floyd(){//弗洛伊德算法
	for(int k=1;k<=26;++k){
		for(int i=1;i<=26;++i){
			for(int j=1;j<=26;++j){
				if(i==j) continue;
				if(e[i][j]>e[i][k]+e[k][j])
				e[i][j] = e[i][k] + e[k][j];
			}
		}
	}
}
int main()
{
	cin>>arr;
	cin>>brr;
	cin>>n;
	//初始化，将所有的不相同的设为无穷大 
	for(int i = 1; i <= 26; i++) {
		for(int j = 1; j <= 26; j++) {
			if(i == j) e[i][j] = 0;//两个相同的字母互相转化不需要步数 
			else e[i][j] = inf;    //初始将两个字母之间的转化赋值为无穷大 
        }
    }
	long long int sum=0;
	char ch1,ch2;
	while(n--){
		getchar();//吸收回车符
		cin>>ch1>>ch2;
		if(ch1!=ch2)//排除两个相等的情况
		e[ch1-'a'+1][ch2-'a'+1]=1; 
	} 
	floyd();
	int len=strlen(arr);
	for(int i=0;i<len;++i){
		sum+=e[arr[i]-'a'+1][brr[i]-'a'+1];
	} 
	if(sum<inf) cout<<sum<<endl;
	else cout<<"-1"<<endl;
	return 0;
}

