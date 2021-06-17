#include<iostream>
using namespace std;

void printingArray(int,int);

int main()
{   
    int arr[11] = {1, 3, 2, 6, -1, 4, 1, 8, 9, 2};
    int n=sizeof(arr)/sizeof(arr[0]);

    //Insert Operation at index 3
    int pos=3, ins=50;
    for(int i=n;i>=pos;i--)
    {   
        //cout<<arr[i]<<" "<<arr[i-1]<<endl;
        arr[i]=arr[i-1];
    }
    arr[pos]=ins;

    printingArray(arr[n],n);
    
    //Largest & Second Largest
    sort(arr,arr+n);
    cout<<arr[n-1]<<" "<<arr[n-2]<<endl;

    //Largest & Second Largest without sort function
    int largest=0, secondLargest=0;;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>largest)
            largest=arr[i];
    }
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=largest)
        {   
            if(arr[i]>secondLargest)
                secondLargest=arr[i];
        }
    }
    cout<<largest<<" "<<secondLargest<<endl;

    //Sorting Array
    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<n;j++)
        {
            if(arr[j]>arr[j+1])
            {  
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }

    printingArray(arr[n],n);

    //Search Operation
    int x=6;
    for(int i=0;i<n;i++)
        if(arr[i]==x) cout<<i<<endl;
    
    //Deletion Operation
    int r=6;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==r)
        {
            for(int j=i;j<n;j++)
                arr[j]=arr[j+1];
        }   
    }

    printingArray(arr[n],n);

    //Move all zeroes to end
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
             for(int j=i+1;j<n;j++)
             {
                  if(arr[j]!=0)
                  {
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                  }
             }
        }
    }
    
    printingArray(arr[n],n);

    //Replace Operation
    int p=99;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==2)
        {
            arr[i]=p;
        }
    }
    
    printingArray(arr[n],n);

}

void printingArray(int arr[],int n){
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//All operations are working, need to check each of
//operation separately to understand their working.