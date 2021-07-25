//Time Complexity: O(logn)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int target)
{
    while(low<=high)
    {   
        int mid=(low+high)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[mid]<target)
        {
            return binarySearch(arr, mid+1, high, target);
        }
        if(arr[mid]>target)
        {
            return binarySearch(arr, low, mid-1, target);
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