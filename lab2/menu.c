#include <iostream>
#include <stdlib.h>
void quit()
{
    exit(0);
}
void hello()
{
    cout<<"hello word!"<<endl;
}
void help()
{
    cout<<"You can read the documention to get help."<<endl;
}
void add()
{
    double a,b,sum;
    cout<<"please input two numbers:"<<endl;
    cin>>a>>b;
    sum=a+b;
    cout<<a<<"+"<<b<<"="<<sum<<endl;
}
void sub()
{
    double a,b,dif;
    cout<<"please intput two numbers:"<<endl;
    cin>>a>>b;
    dif=a-b;
    cout<<a<<"-"<<b<<"="<<dif<<endl;
}
void multi()
{
    double a,b,pro;
    cout<<"please input two numbers:"<<endl;
    cin>>a>>b;
    pro=a*b;
    cout<<a<<"*"<<b<<"="<<pro<<endl;
}
void div()
{
    double a,b,div;
    cout<<"please input two numbers:"<<endl;
    cin>>a>>b;
    if(b==0)
    {
        cout<<"Error:divisor can not be zero!"<<endl;
    }
    else
    {
        div=a/b;
        cout<<a<<"/"<<b<<"="<<div<<endl; 
    }
}
void bigger()
{
    double a,b,bigger;
    cout<<"please input two numbers:"<<endl;
    cin>>a>>b;
    bigger=a>b?a:b;
    cout<<bigger<<"is bigger than the other."<<endl;
}
void main()
{
    
}
