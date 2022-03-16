#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class mergeSortClass
{
    public:
    static void mergeSort(int *arr, int start, int end)
    {       
            int mid;
            if(start<end)
            {
                //divide the array at mid and sort independently using merge sort
                mid=start+(end-start)/2;
                mergeSort(arr, start, mid);
                mergeSort(arr, mid+1, end);
                merge(arr, start, mid, end);
            }
    }

    // Merge sort algorithm
    static void merge(int *arr, int start, int mid, int end)
    {
        // Build temp array to avoid modifying the original contents
        int sortedArray[10];
        int i=start, j=mid+1, k=start;

        // While both sub-array have values, then try and merge them in sorted order
        while(i<=mid && j<=end)
        {
            if(arr[i]<=arr[j])
            {
                sortedArray[k]=arr[i];
                i++, k++;
            }
            else
            {
                sortedArray[k]=arr[j];
                j++, k++;
            }
        }

        // Add the rest of the values from the start sub-array into the result
        while(i<=mid)
        {
            sortedArray[k]=arr[i];
            i++, k++;
        }
        
        // Add the rest of the values from the end sub-array into the result
        while(j<=end)
        {
            sortedArray[k]=arr[j];
            j++, k++;
        }

        for(int i=start; i<k; i++)
        {
            arr[i]=sortedArray[i];
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
    mergeSortClass::mergeSort(arr, 0, size-1);
    mergeSortClass::printArray(arr, size);
}