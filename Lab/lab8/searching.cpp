#include <iostream>

using namespace std;
int main(){
    int n,temp;
    cout<<"Enter total numbers to store in array  ";
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers\n";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"\nChoose Searching Algorithm\n";
    cout<<"1.Linear Search\n2.Binary Search\n";
    int ch;
    cin>>ch;
    cout<<"Enter Data to be searched\n";
    int data,count =0;
    cin>>data;
    switch(ch){
        case 1:  // Linear Search
            for(int i =0;i<n;i++){
                if(arr[i]==data){
                    count++;
                    cout<<"Data found"<<endl;
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

