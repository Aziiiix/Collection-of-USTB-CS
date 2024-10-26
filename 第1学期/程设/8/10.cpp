#include<iostream>
#include<algorithm>
using namespace std;
 
int get_min(int num[],int cnt)
{
    int ans=0;
    for(int i=1;i<=cnt;i++)
        ans=ans*10+num[i];
    return ans;
}
int get_max(int num[],int cnt)
{
    int ans=0;
    for(int i=cnt;i>=1;i--)
        ans=ans*10+num[i];
    return ans;
}
void pretreat(int n,int num[],int &cnt)
{
    while(n)
    {
        num[++cnt]=n%10;
        n/=10;
    }
}
bool check(int n,int out[],int count)
{
    for(int i=1;i<=count-1;i++)
    {
        if(n==out[i])
            return 1;
    }
    return 0;
}
 
int main()
{
    int n=0,count=0,out[1001];
    cin>>n;
    while(count<1000)//�������1000������
    {
        cout<<n<<" ";
        int num[10000],cnt=0;
        pretreat(n,num,cnt);//����������n������λ�ֽ⵽num������
        sort(num+1,num+cnt+1);//��num�����������
        n=get_max(num,cnt)-get_min(num,cnt);//�ֱ�Ӵ�С�ʹ�С������Ϻ����
        out[++count]=n;//��¼�����������������
        if(check(n,out,count))//����Ƿ�ʼ�ظ�
        {
            cout<<n;//���ظ�����������Ȼ���������
            break;
        }
    }
    
    return 0;
}
