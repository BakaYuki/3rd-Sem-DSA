// Linear queue


#include <iostream>
#define max 4
using namespace std;

int main(){
    int rear=-1, front = -1;
    int data, queue[max];
    int ch = 0;
    while(ch!=4){
        cout<<"Choose an option:\n1.Enque\n2.Deque\n3.Display data in queue\n4.Exit\n";
        cin>>ch;

        switch(ch){
            case 1:
                if(rear == max - 1){
                    cout<<"Queue over flow\n\n";
                    break;
                }
                if(front == -1){
                front = front + 1;
                }
                rear++;
                cout<<"Enter data \n";
                cin>>data;
                queue[rear] = data; 
                cout<<"Data inserted!\n\n";
                break;
            
            case 2:
                
                if(front == -1){
                    cout<<"Queue under flow\n\n";
                    break;
                }

                cout<<"Dequed Data is "<<queue[front]<<endl;
                front = front + 1;
                if(front > rear){
                    front = -1;
                    rear = -1;
                }
                break;

            case 3:
                int x = front;
                if(x == -1){
                    cout<<"No data in queue\n\n";
                    break;
                }
                cout<<"Data is:\n";
                for(x;x<=rear;x++){
                    cout<<queue[x]<<endl;
                }
                cout<<"\n";
                break;
        }
    }    
}