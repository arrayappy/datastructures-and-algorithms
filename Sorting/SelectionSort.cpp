/*
Advantage: Does less memory writes compare to others.
Algorithm: 
Find out 1st min element and put it in the 1st position.
Find out 2nd min element and put it in the 2nd position.
Find out 3rd min element and put it in the 3rd position.
*/
#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class selectionSortClass
{
    public:
    static vector<int> selectionSort(vector<int> & arr, int n)
    {   
        //In-Place Approach
        for(int i=0; i<n; i++)
        {
            int minIndex=i;
            for(int j=i+1; j<n; j++)
            {
                if(arr[j]<arr[minIndex])
                {
                    swap(arr[j], arr[minIndex]);
                }
            }
        }
        return arr;

        //Naiva Approach
        // vector<int> temp(n);
        // for(int i=0; i<n; i++)
        // {   
        //     int minIndex=0;
        //     for(int j=1; j<n; j++)
        //     {
        //         if(arr[j]<arr[minIndex])
        //         {
        //             minIndex=j;
        //         }
        //     }
        //     temp[i]=arr[minIndex];
        //     arr[minIndex]=INT_MAX;   
        // }
        // return temp;
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
    selectionSortClass::selectionSort(arr, n);
    selectionSortClass::printArray(arr, n);
}