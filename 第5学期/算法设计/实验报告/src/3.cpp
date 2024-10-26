#include<iostream>
using namespace std;
int main(){
    double x,y;
    int n;
    cin>>x>>y>>n;
    double first=0.0,last=10.;
    float temp;
    while(last-first >= 0.0001){
        double sum=0.0;
        temp=(first+last)/2;
        double x1=1;
        for(int i=1;i<=n;i++){
            x1*=(temp+1);
            sum+=1.*y/x1;
        }
        if(sum>x){
            first=temp;
        }
        if(sum<x){
            last=temp;
        }
    }
    cout.precision(2); 
    cout<<temp*100<<endl;
    return 0;
}
