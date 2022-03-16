/*
Advantage: Used in practice for small arrays.
Algorithm:
1: Iterate from arr[1] to arr[n] over the array. 
2: Compare the current element (key) to its predecessor. 
3: If the key element is smaller than its predecessor, compare 
   it to the elements before. Move the greater elements one 
   position up to make space for the swapped element.
*/
#include<bits/stdc++.h>
using namespace std;

class insertionSortClass
{
    public:
    static vector<int> insertionSort(vector<int> & arr, int n)
    {   
        //In-Place Approach
        for(int i=1; i<n; i++)
        {
            int key = arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j--;
            } 
            arr[j+1]=key;
        }
        return arr;
    }

    static void printArray(vector<int> arr, int n)
    {
        for(int i=0; i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main()
{   
    vector<int> arr = {45, 68, 95, 27, 88, 122};
    int n = arr.size();
    insertionSortClass::insertionSort(arr, n);
    insertionSortClass::printArray(arr, n);
}