#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> Stack;
    Stack.push(10);
    Stack.push(20);
    Stack.push(30);
    Stack.pop();
    Stack.push(40);
    while(!Stack.empty())
    {
        cout<<Stack.top()<<endl;
        Stack.pop();
    }
}