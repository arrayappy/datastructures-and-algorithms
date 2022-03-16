#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class quickSortClass
{
    public:

    // partition the array using last element as pivot
    static int partition (int *arr, int start, int end) 
    {   
        int pivot = arr[end];
        int i = (start - 1);
        for (int j = start; j <= end- 1; j++) 
        {
            // if current element is smaller than pivot, increment the start element
            // swap elements at i and j
            if (arr[j] <= pivot) 
            { 
                i++;    // increment index of smaller element 
                swap(arr[i], arr[j]); 
            } 
        }
        swap(arr[i + 1], arr[end]); 
        return (i + 1); 
    } 

    // quicksort algorithm
    static void quickSort(int *arr, int start, int end) 
    { 
        if (start < end) 
        { 
            // partition the array 
            int pivot = partition(arr, start, end); 
    
            // sort the sub arrays independently 
            quickSort(arr, start, pivot - 1); 
            quickSort(arr, pivot + 1, end); 
        } 
    } 

    static void printArray(int *arr, int size)
    {
        for(int i=0; i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main()
{       
    int arr[10] = {1,3,22,10,11,100,9,4,6,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSortClass::quickSort(arr, 0, size-1);
    quickSortClass::printArray(arr, size);
}