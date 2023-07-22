#include<iostream>
#include<stdlib.h>
#define max 5

using namespace std;

int main()
{
    int rear = -1, front = -1;
    int data,queue[max], ch=0;
    while(ch != 4)
    {
    cout<<"Choose your option:\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n";
    cin>>ch;

    switch(ch)
    {
        case 1:
        if(rear == (max -1))
        {
            cout<<"queue is overflow\n";
            break;
        }
        else{
            cout<<"Enter data\n";
            cin>>data;
            rear = rear +1;
            if (front == -1)
            {
                front = front +1;
            }
            queue[rear]= data;
        }
        break;

        case 2:
        if (front == -1)
        {
            cout<<"queue is underflow\n";
            break;
        }
        else
        {
            data= queue[front];
            cout<<"Dequeued data is:"<<data<<"\n";
            front = front + 1;
        
            if(front>rear)
            {
                front = -1;
                rear = -1;
            }
        }
        break;

        case 3:
        int x = front;
        if(x==-1)
        {
            cout<<"Queue is empty\n";
            break;
        }
        for(x;x<=rear;x++)
        {
            cout<<"Data:"<<queue[x]<<"\n";
        }
        break;


    }
    }
}