#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

using namespace std;

int main()
{
    int n=0,TOP=-1,stack[MAX];
    while(n!=4)
    {
        cout<<"\nEnter choice\n"<<"1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n";
        cin>>n;

        switch(n)
        {
            case 1:
            if(TOP==MAX-1)
            {
                cout<<"stack overflow\n";
            }
            else
            {
                cout<<"Enter value:";
                TOP=TOP+1;
                cin>>stack[TOP];
            }
            break;

            case 2:
            if(TOP==-1)
            {
                cout<<"Stack Empty\n";
            }
            else
            {
                cout<<"Data popped\n";
                cout<<"Popped data is:"<<stack[TOP];
                TOP=TOP-1;
            }
            break;

            case 3:
            if(TOP==-1)
            {
                cout<<"Stack Empty\n";
            }
            else
            {
                for(int i=0;i<=TOP;i++)
                {
                    cout<<stack[i]<<"\n";
                }
            }
                break;

                case 4:
                exit(0);
                break;

                default:
                cout<<"Enter valid choice:";
        }
    }
}