#include<iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap
{   
    public:
    int size;
    int capacity;
    int *harr;
    MinHeap(int cap)
    {
        size = 0;
        capacity = cap;
        harr = new int[cap];
    }
     
    int left(int i)
    {
        return (2*i + 1);
    }
    int right(int i)
    {
        return (2*i + 2);
    }
    int parent(int i)
    {
        return (i-1)/2;
    }

    void insertKey(int data)
    {
        if(size==capacity)
        {
            cout<<"Heap is full!"<<endl;
            return;
        }
        size++;
        harr[size-1]=data;

        int i = size-1;
        while(i!=0 && harr[parent(i)]>harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i=parent(i);
        }
    }
    
    void minHeapify(int i)
    {
        int l=left(i);
        int r=right(i);
        int smallest=i;
        if(l<size && harr[l]<harr[i])
            smallest = l;
        if(r<size && harr[i]<harr[smallest])
            smallest = r;
        if(smallest!=i)
        {
            swap(harr[i], harr[smallest]);
            minHeapify(smallest);
        }
    }
    
    int extractMin()
    {
        if(size==0)
            return INT_MAX;
        if(size==1)
        {
            size--;
            return harr[0];
        }
        swap(harr[0], harr[size-1]);
        size--;
        minHeapify(0);
        return harr[size]; 
    }

    void decreaseKey(int i, int data)
    {
        harr[i] = data;
        while(i!=0 && harr[i]<harr[parent(i)])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
    
    void printHeap()
    {
        for(int i=0;i<size;i++)
        {
            cout<<harr[i]<<" ";
        }
    }
};

int main()
{  
    MinHeap heap(10);
    heap.insertKey(50);
    heap.insertKey(20);
    heap.insertKey(10);
    heap.insertKey(40);
    heap.deleteKey(20);
    heap.printHeap();
}