
#include <iostream>

using namespace std;

int whoIsMonkeyKing(int,int );

int main()
{
	int m,n;
	cout<<"input m: ";
	cin>>m;
	cout<<"input n: ";
	cin>>n;
    cout<<"king: "<<whoIsMonkeyKing(m,n)<<endl;
    return 0;
}


int whoIsMonkeyKing(int m,int n) //m为猴子个数，n为最大报数
{
    if(m<1 || n<1)
    {
        cout<<"输入参数错误"<<endl;
        return -1;
    }
    int *p = new int[m];
    int *q = p,M = m;
    int res;
    for(int i=0; i<m; i++)
    {
        p[i]=1;
    }
    while(M!=1)
    {
        int i=0;
        while(i!=n)
        {
            if(q==p+m)
            {
                q = p;
            }
            if(*q++==1)
            {
                ++i;
            }
        }
        *(q-1) = 0;
        --M;
    }
    for(int i=0; i<m; i++)
    {
        if(*(p+i)==1)
        {
            res = i+1;
            break;
        }
        else
            continue;
    }
    delete[] p;
    return res;
}
