//
//  main.cpp
//  八皇后
//
//  Created by bondsam on 2018/4/21.
//  Copyright © 2018年 bondsam. All rights reserved.
//

#include<iostream>
#include <cmath>
using namespace std;
const int stacksize = 1024;//随便设定一个足够大的数
int num = 0; //用于统计方案数。

class stack
{
private:
    int data[stacksize];
    int top;
public:
    stack() { top = 0; };
    void push(int x);
    void pop();
    bool empty();
    bool check(int k);//判断列和对角线是否符合要求
    void print(int n);//打印方案
    void Queen(int n);//方案
};

bool stack::empty()
{
    if (top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void stack::push(int x)
{
    if (top >=stacksize)//异常操作处理
    {
        throw"上溢";
    }
    else
    {
        top++;
        data[top] = x;
    }
}

void stack::pop()
{
    if (empty())
    {
        throw"下溢";
    }
    else
    {
        top--;
    }
}

bool stack::check(int k)
{
    for (int i = 1; i < k; i++)
    {
        if((data[i]==data[k])||(fabs(data[i]-data[k])==fabs(i-k)))
        {
            return false;
        }
    }
    return true;
}

void stack::print(int n)
{
    cout << "第" << num << "种方案:" << endl;
    int i, j;
    cout<<"---------------------------"<<endl;
    for (i = 1; i <= n; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (j == data[i])
                cout<<'Q';
            else
                cout<<'*';
        }
        cout<<endl;
    }
    
    cout<<"---------------------------"<<endl;
}

void stack::Queen(int n)
{
    
    int k;
    k=1;
    data[k]=0;
    while (k>0) {
        data[k]++;
        while (data[k]<=n&&!check(k)) {
            data[k]++;
        }
        if (data[k]<=n) {
            if (k==n) {
                num++;
                print(n);
            }
            else
            {
                k++;
                data[k]=0;
            }
        }
        else
            k--;
    }
}

int main()
{
    int n;
    cin>>n;
    stack Q;
    Q.Queen(n);
}

