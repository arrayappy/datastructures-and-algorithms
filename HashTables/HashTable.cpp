//This hashtable implementation doesn't handle collision.
#include<bits/stdc++.h>
using namespace std;

int arr[10];
class HashTable
{
    public:
    HashTable()
    {
        for(int i=0;i<10;i++)
            arr[i]=-1;
    }

    void insert(int key)
    {
        int k=key%10;
        if(arr[k]==-1)
        {
            arr[k]=key;
        }
        else
        {
            cout<<"Can't insert because collision occured!"<<endl;
        }
    }
    void remove(int key)
    {
        int k=key%10;
        if(arr[k]!=-1)
        {
            arr[k]=-1;
        }
        else
        {
            cout<<"Not found"<<endl;
        }
    }

    void search(int key)
    {
        int k=key%10;
        if(arr[k]==key)
        {
            cout<<"Found"<<endl;
        }
        else
        {
            cout<<"Not found"<<endl;
        }
    }

    void display()
    {
        for(int i=0;i<10;i++)
        {
            if(arr[i]!=-1)
            {
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }
};


int main()
{
    HashTable ht;
    while(1)
    {   
        cout<<"1. Insert 2.Delete 3. Search 4. Display 5. Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice, key;
        cin>>choice;
        switch(choice)
        {
            case 1: cin>>key;
                    ht.insert(key);
                    break;
            case 2: cin>>key;
                    ht.remove(key);
                    break;
            case 3: cin>>key;
                    ht.search(key);
                    break;
            case 4: ht.display();
                    break;
            case 5: exit(0);
            default: cout<<"Try again, wrong choice entered!"<<endl;
        }
    }
}