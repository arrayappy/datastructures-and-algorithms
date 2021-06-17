#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    /* 
    Variable next is a pointer to the struct Node
    It is also called as self referential structures
    */
    Node *next; 
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void printList(Node *head)
{   
    if(head==NULL)
    {
        cout<<"LinkedList is empty";
    }
    Node *current=head;
    while(current!=NULL)
    {
        cout<<(current->data)<<endl;
        current=current->next;
    }
}

void printListRecursive(Node *head)
{
    if(head==NULL)
    {
        cout<<"LinkedList is empty";
    }
    Node *current=head;
    cout<<(current->data)<<endl;
    printListRecursive(current->next);
}

void search(Node* head, int n)
{
    int pos=0;
    while(head!=NULL)
    {
        if(head->data==n)
        {
            cout<<pos<<endl;
        }
        head=head->next;
        pos++;
    }
}

void insertBegin(Node** head, int new_data)
{
    Node* new_node = new Node(new_data);
    new_node->next=(*head);
    (*head)=new_node;
}

void insertEnd(Node** head, int new_data)
{
    Node* new_node = new Node(new_data);
    Node* last=(*head);
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
}

//insert a new_node at given node
void insertAt(Node** head, int new_data)
{
    if(head==NULL)
    {
        cout<<"Linkedlist doesn't have given position";
        return;
    }
    Node *new_node = new Node(new_data);
    new_node->next=(*head);
    (*head)=new_node;
}

//insert a new_node after given prev_node
void insertAfter(Node** prev_node, int new_data)
{
    if(prev_node==NULL)
    {
        cout<<"Linkedlist doesn't have given position";
        return;
    }
    Node *new_node = new Node(new_data);
    new_node->next=(*prev_node)->next;
    (*prev_node)->next=new_node;
}

void deleteBegin(Node** head)
{   
    if(*head==NULL)
    {
        cout<<"Linkedlist is empty";
    }
    (*head)=(*head)->next;
}

void deleteEnd(Node** head)
{  
    if(*head!=NULL)
    {
        if((*head)->next==NULL)
        {
            *head=NULL;
        }
    }
    Node* last=(*head);
    while(last->next->next!=NULL)
    {
        last=last->next;
    }
    last->next=NULL;
}

//delete element at given position
void deleteAt(Node** head, int pos)
{   Node *current=*head;
    Node *prev_node=NULL;
    while(pos!=0)
    {   prev_node=current;
        current=current->next;
        pos--;
    }
    prev_node->next=current->next;
    current->next=NULL;
}

//give a key, deletes first occurrence of given key
void deleteNode(Node** head, int key)
{
    Node *current=(*head);
    Node *prev_node=NULL;
    while(current->data!=key)
    {
        prev_node=current;
        current=current->next;
    }
    prev_node->next=current->next;
    current->next=NULL;
}

int main()
{
/* 
1) 'Node head=new Node(10);' Here head is a instance of struct Node
2) 'Node *head=new Node(10);' Here *head is struct pointer of Node because it stores address of struct Node 
   And we can access data and next in Node using 'head->data' and 'head->next'
*/
    Node* head = NULL;

    // Node *head=new Node(10);
    // head->next=new Node(20);
    // head->next->next=new Node(30);
    // cout<<head->next<<endl;
    // cout<<head->next->next<<endl;    
    // cout<<head->next->next->next<<endl;
    // cout<<head->data;
    // cout<<head->next->data;
    // cout<<head->next->next->data<<endl;

    insertBegin(&head,20);
    insertBegin(&head,15);
    insertBegin(&head,10);
    insertEnd(&head,11);
    insertEnd(&head,12);
    insertEnd(&head,13);
    insertAt(&head->next,50);
    insertAfter(&(head->next),100);
    deleteBegin(&head);
    deleteEnd(&head);
    deleteAt(&head,1);
    deleteNode(&head,20);
    printList(head);
    //printListRecursive(head);
}