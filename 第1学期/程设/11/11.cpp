#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
 
int main()
{
    int n,m,*point[1000]={NULL};
    cin>>n>>m;//���������ά��
    for(int i=0;i<n;i++)
    {
        point[i]=new int [m];
        for(int j=0;j<m;j++)
        {
            cin>>point[i][j];
        }
    }//���������Ϣ
 
    int ans=0;//�����
    for(int dimentionality=0;dimentionality<m;dimentionality++)//ÿһά��������
    {
        int *temp=new int [m];//��һ����ʱ����������
        int local_ans=0;
        for(int pt=0;pt<n;pt++)
        {
            temp[pt]=point[pt][dimentionality];
        }
        sort(temp,temp+n);//����
        for(int i=n-1;i>=n/2;i--)//���������������
        {
            local_ans+=temp[i]-temp[n-1-i];
        }
        ans+=local_ans;
    }
 
    cout<<ans;
    return 0;
}
