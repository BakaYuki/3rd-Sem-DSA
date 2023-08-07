// Basic Stack Functions

#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 5
using namespace std;


int main(){
    int n=0,TOP = -1, stack[MAX];

    while(n!=4){
        cout<<"Enter Choice \n1. PUSH\n2. POP\n3.Display\n4.Exit\n";
        cin>>n;

        switch(n){
            case 1:
            if(TOP == MAX -1){
                cout<<"Stack Overflow\nPlease Choose another option\n";
            }
            else{
                cout<<"Enter value\n";
                TOP = TOP + 1;
                cin>>stack[TOP];
                cout<<"Data pushed\n";
            }
            break;

            case 2:
            if(TOP==-1){
                cout<<"Stack Empty\n";
            }
            else{

                cout<<"Data Popped\n"<<stack[TOP]<<endl;
                TOP = TOP -1;
            }
            break;
            case 3:
            cout<<endl;
            if(TOP == -1){
                cout<<"Stack is empty\n";
            }
            else{
                cout<<"Data in Stack:\n";
                for(int i=0;i<=TOP;i++){
                    cout<<stack[i]<<endl;
                }
            }
            break;
            case 4:
            exit(0);
            break;

            default:
            cout<<"Enter proper choice\n";
            break;
        }
        cout<<"\nWould u like to continue?  y / n  ";
        char ch;
        cin>>ch;
        if(ch == 'y'){
            continue;
        }
        else{
            exit(0);
        }

    }
}