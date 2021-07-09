//Time Complexity: O(logn)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int target)
{
    while(left<=right)
    {   
        int middle=(left+right)/2;
        if(arr[middle]==target)
        {
            return middle;
        }
        if(arr[middle]<target)
        {
            return binarySearch(arr, middle+1, right, target);
        }
        if(arr[middle]>target)
        {
            return binarySearch(arr, left, middle-1, target);
        }
    }
    return -1; 
}

int main()
{   
    int size, target;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter array elements: ";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter element to search: ";
    cin>>target;
    sort(arr,arr+size);

    int result = binarySearch(arr, 0, size-1, target);

    if(result==-1)
        cout<<"Element is not found"<<endl;
    else
        cout<<"Element is found at index " << result<<endl;
    return 0;
}