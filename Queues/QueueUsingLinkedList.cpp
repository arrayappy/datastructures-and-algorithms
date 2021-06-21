#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int length;
    Queue() { length = 0; }
    struct Node
    {
        int data;
        struct Node *next;
        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
    };

    struct Node* front = NULL;
    struct Node* rear = NULL;

    bool isEmpty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }

    void enqueue(int data)
    {
        Node *temp = new Node(data);
        if (front==NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear=temp;
        }
        length++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            front = front->next;
            length--;
        }
    }

    int peek()
    {
        return front->data;
    }

    int tail()
    {
        return rear->data;
    }

    int size()
    {
        return length;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    cout << q.peek() << endl;
    cout << q.tail() << endl;
    cout << q.size() << endl;
    cout << q.isEmpty ()<<endl;
    while (!(q.isEmpty()))
    {
        cout << q.peek() << " ";
        q.dequeue();
    }
}