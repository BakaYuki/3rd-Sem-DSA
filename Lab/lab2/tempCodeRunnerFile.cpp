// Linear queue


#include <iostream>
#include <conio.h>
#define max 5
using namespace std;

int main(){
    int rear=-1, front = -1;
    int data, queue[max];
    int ch = 0;
    while(ch!=4){
        cout<<"Choose an option:\n1.Enque\n2.Deque\n3.Display all\n4.Exit\n";
        cin>>ch;

        switch(ch){
            case 1:
                if(rear == max - 1){
                    cout<<"Queue over flow";
                    break;
                }
                if(front == -1){
                front = front + 1;
                }
                rear++;
                cout<<"Enter data \n";
                cin>>data;
                queue[rear] = data; 
                break;
            
            case 2:
                if(front > rear){
                    front = -1;
                    rear - -1;
                }
                if(front == -1){
                    cout<<"Queue under flow";
                    break;
                }

                cout<<"Dequed Data is "<<queue[front];
                front = front + 1;
                break;

            case 3:
                int x = front;
                cout<<"Data is:\n";
                for(x;x<=rear;x++){
                    cout<<queue[x]<<endl;
                }
        }
    }    
}