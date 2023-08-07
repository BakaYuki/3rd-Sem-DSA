#include <iostream>

using namespace std;
void display(int *a,int x);
int main(){
    int n,temp;
    cout<<"Enter total numbers to store in array  ";
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers\n";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Choose Sorting Method"<<endl;
    cout<<"1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n";
    int ch;
    cin>>ch;
    switch(ch){
        case 1:  //Bubble Sort
            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-i-1;j++){
                    if(arr[j]>arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
            display(arr,n);
            break;

        case 2:    //Selection Sort
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(arr[j]<arr[i]){
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp; 
                    }
                }
            }
            display(arr,n);
            break;
        
        case 3:
            for(int i=1;i<n;i++){
                temp = arr[i];
                int j = i -1;
                while(j>=0 && arr[j] > temp){
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = temp;
            }
            display(arr,n);
            break;
        
        case 4:
            for(int i=0;i<n;i++){
                temp = arr[i];
                int j;
                for(j = i-1;j>=0;j--){
                    if(temp<arr[j]){
                        arr[j+1]=arr[j];
                    }
                    else{
                        break;
                    }
                }
                arr[j+1] = temp;
            }
        display(arr,n);
        break;
    }
    cout<<"\nChoose Searching Algorithm\n";
    cout<<"1.Linear Search\n2.Binary Search\n";
    cin>>ch;
    cout<<"Enter Data to be searched\n";
    int data,count =0;
    cin>>data;
    switch(ch){
        case 1:  // Linear Search
            for(int i =0;i<n;i++){
                if(arr[i]==data){
                    count++;
                    cout<<"Data found at position "<<arr[i]<<endl;
                }
            }
        break;
        case 2:
            int beg = 0,end = n-1,mid;
            while(beg<=end ){
                mid = (beg + end)/2;
                if(data<arr[mid]){
                    end = mid-1;
                }
                else if(data>arr[mid]){
                    beg = mid+1;
                }
                else{
                    break;
                }
            }
                if(arr[mid]==data){
                    cout<<"Data found\n";
                    count++;
                }
        break;
    }
    if(count==0){
        cout<<"Data not found";
    }
}

void display(int *a,int x){
    cout<<"In order: \n";
    for(int i = 0;i<x;i++){
        cout<<*(a+i)<<endl;
    }
}

