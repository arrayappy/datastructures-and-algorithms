#include<bits/stdc++.h>
using namespace std;
#define MAX 100

class Stack
{
    public:
        int top;
        int a[MAX];

    Stack()
    {
        top = -1;
    }

    bool push(int data)
    {
        if(top>=MAX-1)
        {
            cout<<"Stack is Overflow";
            return false;
        }
        else
        {
            top++;
            a[top]=data;
            return true;
        }
    }

    int pop()
    {
        if(top<0)
        {
            cout<<"Stack is Underflow";
            return 0;
        }
        else
        {
            int temp=a[top--];
            return temp;
        }
    }

    int peek()
    {
        if(top<0)
        {
            cout<<"Stack is Empty";
            return 0;
        }
        else
        {
            return a[top];
        }
    }

    bool isEmpty()
    {
        return (top==-1);
    }

};

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<endl;
    s.push(40);
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    while(!s.isEmpty())
    {
        cout<<s.peek()<<" ";
        s.pop();
    }
}