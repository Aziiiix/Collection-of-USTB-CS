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
	//�����������Ӵ������㳤�� 
	int i;
	//��ʾ�Ƚϵĵ�һλ�±� 
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
					//return 0�������� 
				}
				//��ѭ���жϳ������Ӵ����һλ���⴦�� 
			}
			else{
			if(major[count]==major_son[j])
			{
				count++;
				continue;
			}
			//���ӵ�i�ʼ���������һ�������ѭ�� 
			else
			{
				break;
			}
			//������������ѭ�� 
		}
		}
	}
	cout<<"can't find"<<endl;
}
