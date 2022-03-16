/*
Advantage: Easy to implement.
Algorithm: 
Repeatedly swapping the adjacent elements if they are in wrong order.
*/
#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class bubbleSortClass
{
    public:
    static vector<int> bubbleSort(vector<int> & arr, int n)
    {   
        //swapped variable will check whether array is swapped or not
        //after every pass, if sorted, then it returns the array.
        bool swapped = false;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(arr[j], arr[j+1]);
                    swapped = true;
                }
            }
            if(swapped==false)
                return arr;
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
    bubbleSortClass::bubbleSort(arr, n);
    bubbleSortClass::printArray(arr, n);
}