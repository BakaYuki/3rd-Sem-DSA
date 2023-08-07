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
            for(int i=0;i<n-1;i++){
                temp = arr[i];
                int j = i + 1;
                while(temp>arr[j]){
                    arr[j-1]=arr[j];
                    j++;
                    if(j==n){
                        break;
                    }
                }
            }
        display(arr,n);
        break;
        
        case 4:
            for(int i =0;i<n;i++){
                temp = arr[i];
                int j = i-1;
                for(int j = j-1;j>=0;j--){
                    if(temp<arr[j]){
                        arr[j+1] = arr[j];
                    }
                    
                    arr[j+1]=temp;
                }
            }
            display(arr,n);
            break;
    }
}

void display(int *a,int x){
    cout<<"In order: \n";
    for(int i = 0;i<x;i++){
        cout<<*(a+i)<<endl;
    }
}