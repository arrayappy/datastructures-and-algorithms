#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    struct Node {
    int data;
    Node *next; 
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

struct Node* head = NULL;

void push(int data)
{   
    struct Node* temp = new Node(data);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void pop()
{
    if(head==NULL)
    {
        cout<<"Stack is emptttty"<<endl;
    }
    else
    {
        //cout<<head->data<<endl;
        head=head->next;
    }
}

void traverse()
{   
    if(head==NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    struct Node* temp = head;
    while(temp!=NULL)
    {
        cout<<(temp->data)<<endl;
        temp=temp->next;
    }
}

void peek()
{
    cout<<head->data<<endl;
}
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.push(40);
    s.traverse();
    s.peek();
}
