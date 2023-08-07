#include<iostream>
#include <conio.h>

using namespace std;


int main()
{
    int n,count = 0;
    cout<<"Enter total array elements:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"Enter data to be searched:\n";
    int value;
    cin>>value;

    cout<<"Enter searching method:\n 1.Binary Search\n 2.Linear Search\n";
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
            int beg,end,mid;
            beg=0;
            end=(n-1);
            mid= (beg+end)/2;
            while(beg<=end && arr[mid]!=value)
            {
                if(value<arr[mid])
                {
                    end=mid-1;
                }
                else
                {
                    beg=mid+1;
                }
                mid=(beg+end)/2;
            }
            if(arr[mid]==value)
            {
                cout<<"Data found at location "<<mid;
            }
            else
            {
                cout<<"DATA NOT FOUND\n";
            }

        break;

        case 2:
        for(int i=0;i<n;i++)
        {
            if(value==arr[i])
            {
                count++;
                cout<<"Data Found at position"<<arr[i]<<"\n";
            }
            if(count==0)
            {
                cout<<"DATA NOT FOUND\n";
            }
        }
        break;

        default:
        break;
    }
}