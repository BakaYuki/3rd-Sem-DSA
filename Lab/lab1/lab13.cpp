// Evaluating expression of prefix

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){
    char arr[20];
    int top = -1;
    cout<<"Enter the expression\n";
    cin>>arr;
    strrev(arr);
    int len = strlen(arr);
    int stack[len];
    for(int i=0;i<len;i++){
        if(arr[i]>47 && arr[i]<58){
            top++;
            stack[top] = arr[i] - 48;       
        }
        else{

            int x;
            switch(arr[i])
            {
                case '*':
                x = stack[ top ] * stack[top - 1];
                break;
                
                case '/':
                x = stack[ top ] / stack[top - 1];
                break;

                case '-':
                x = stack[ top ] - stack[top - 1];
                break;

                case '+':
                x = stack[ top ] + stack[top - 1];
                break;
            }
            top--;
            stack[top]=x;
        }
    }
    cout<<"\nEvaluated expression: "<<stack[top];
}