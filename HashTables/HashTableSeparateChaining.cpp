//This hashtable implementation handles collision using separate chaining method.
#include<bits/stdc++.h>
using namespace std;

class HashTable
{   
    private:
    int size;
    list<int> *table;

    public:
    HashTable(int size)
    {
        this->size=size;
        table=new list<int>[this->size]; 
    }

    int hash(int key)
    {
        return (key % size);
    }

    void insert(int key)
    {
        int bucket = hash(key);
        table[bucket].push_front(key);
    }
     
    void remove(int key)
    {   
        int bucket = hash(key);
        auto it = find(table[bucket].begin(), table[bucket].end(), key);
        //iterator points to end() if it didn't found the key in list.
        if(it == table[bucket].end())
            cout<<"Key not found"<<endl;
        table[bucket].erase(it);
    }

    void search(int key)
    {
        int bucket = hash(key);
        auto it = find(table[bucket].begin(), table[bucket].end(), key);
        //iterator points to end() if it didn't found the key in list.
        if(it == table[bucket].end())
            cout<<"Not found"<<endl;
        else
            cout<<"Found"<<endl;
    }   

    void display()
    {
        for(int i=0; i<size; i++)
        {
            cout<<i<<": ";
            for(auto it = table[i].begin(); it!=table[i].end(); it++)
            {
                cout<<(*it)<<" "; 
            }
            cout<<endl;
        }
    }
};

int main()
{
    cout<<"Enter size of the hashtable ";
    int size;
    cin>>size;
    HashTable ht(size);

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