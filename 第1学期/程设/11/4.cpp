//code by Aziiii
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char major[10000];
	char major_son[10000];
	cin>>major;
	cin>>major_son;
	int len1=strlen(major);
	int len2=strlen(major_son);
	//输入主串和子串并计算长度 
	int i;
	//表示比较的第一位下标 
	for(i=0;i<len1;i++)
	{
		int count=i;
		for(int j=0;j<len2;j++)
		{
			if(j==len2-1)
			{
				if(major[count]==major_son[j])
				{
					cout<<"find at "<<i+1;
					return 0;
					//return 0结束进程 
				}
				//当循环判断持续到子串最后一位特殊处理 
			}
			else{
			if(major[count]==major_son[j])
			{
				count++;
				continue;
			}
			//若从第i项开始等于子项第一项则继续循环 
			else
			{
				break;
			}
			//不符合则跳出循环 
		}
		}
	}
	cout<<"can't find"<<endl;
}
