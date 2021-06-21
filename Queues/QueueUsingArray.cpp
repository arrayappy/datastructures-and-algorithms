#include<bits/stdc++.h>
using namespace std;
#define MAX 100

class Queue
{
    public:
        int front, rear;
        int arr[MAX];

    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool push(int data)
    {
        if(rear>=MAX-1)
        {
            cout<<"Queue is Overflow"<<endl;
            return false;
        }
        else
        {
            if(front==-1) 
                front=0;

            rear=rear+1;
            arr[rear]=data;
            return true;
        }
    }

    int pop()
    {
        if(front==-1 || front>rear)
        {
            cout<<"Queue is Underflow"<<endl;
            return 0;
        }
        else
        {
            int temp=arr[front];
            front=front+1;
            return temp;
        }
    }

    int tail()
    {
        if(front<0)
        {
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        else
        {
            return arr[front];
        }
    }

    int peek()
    {
        if(front<0)
        {
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        else
        {
            return arr[rear];
        }
    }

    bool isEmpty()
    {
        return (front==-1);
    }
};

int main()
{
    class Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.pop()<<endl;
    q.push(40);
    cout<<q.peek()<<endl;
    cout<<q.isEmpty()<<endl;
    int i=q.front;
    while(i<=q.rear)
    {
        cout<<q.arr[i]<<" ";
        i++;
    }
}