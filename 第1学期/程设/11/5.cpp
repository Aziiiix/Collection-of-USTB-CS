//code by Aziiii
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char major1[10000];char major2[10000];char major_son[10000];
	cin>>major1>>major2>>major_son;
	int len1=strlen(major1);
	int len2=strlen(major2);
	int lenmin=strlen(major_son);
	//��ʼ��2��������1���Ӵ������㳤�� 
	int check=0;
	for(int i=0;i<len1;i++)
	{
		int count=i;
		for(int j=0;j<lenmin;j++)
		{
			if(j=lenmin-1)
			{
				if(major1[count]==major_son[j])
			{
				check++;
				break;
			}
			}
			else
			{
				if(major1[count]==major_son[j])
			{
				count++;
				continue;
			}
			else break;	
			}
		}
	}
	//�������1�Ƿ����Ӵ� 
	for(int i=0;i<len2;i++)
	{
		int count=i;
		for(int j=0;j<lenmin;j++)
		{
			if(j=lenmin-1)
			{
				if(major2[count]==major_son[j])
			{
				check++;
				break;
			}
			}
			else
			{
				if(major2[count]==major_son[j])
			{
				count++;
				continue;
			}
			else break;	
			}
		}
	}
	//�������2�Ƿ����Ӵ���
	if(check==2) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
