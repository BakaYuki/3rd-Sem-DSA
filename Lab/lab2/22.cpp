// Circular Queue

#include <iostream>
#include <conio.h>
#define max 3
using namespace std;

int main(){
    int front = -1, rear = -1;
    int data, queue[max];
    int ch = 0;
    while(ch!=4){
        cout<<"Choose an option:\n1.Enque\n2.Deque\n3.Display all\n4.Exit\n";
        cin>>ch;
        switch(ch){

            case 1:
                if((rear == (max - 1) && front == 0) || (front == (rear + 1))){
                    cout<<"Queue Overflow\n\n";
                }
                else{
                    if(front == -1){
                    front = 0;
                    }
                    cout<<"Enter data\n";
                    cin>>data;
                    rear = ((rear + 1) % max);
                    queue[rear]=data;
                    cout<<"Data inserted!\n\n";
                }
                    break;
            case 2:

                if(front == -1){
                    cout<<"Queue under flow\n\n";
                    break;
                }
                if(front == rear){
                    cout<<"Dequed Element is "<<queue[front]<<endl<<endl;
                    front = -1;
                    rear = -1;
                }
                else{
                    cout<<"Dequed Element is "<<queue[front]<<endl;
                    front = (front + 1)%max;
                }
                break;

            case 3:
                int x = front;
                cout<<"Elements are: \n";
                for(x;x!=rear; x= ((x + 1)%max)){
                    cout<<queue[x]<<endl;
                }
                cout<<queue[x]<<endl<<endl;
                break;
        }
    }
}