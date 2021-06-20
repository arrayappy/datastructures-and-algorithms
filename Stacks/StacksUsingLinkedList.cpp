#include<bits/stdc++.h>
using namespace std;
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
        cout<<head->data<<endl;
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

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    traverse();
    pop();
    pop();
    traverse();
    push(5);
    traverse();
    peek();
}
