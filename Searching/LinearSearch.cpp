//Time Complexity: O(n)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    if(arr[size]==target)
    {
        return size;
    }
    else if(size>=0)
    {
        return linearSearch(arr, size-1, target);
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

    int result = linearSearch(arr, size-1, target);

    if(result==-1)
        cout<<"Element is not found"<<endl;
    else
        cout<<"Element is found at index " << result<<endl;
    return 0;
}