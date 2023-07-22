#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int checkp(char *s,char *o,int a,int i){
    if( s[a] == '/' || '*' && o[i] == '+'||'-'){
        return 1;
    }
    else if(s[a] == '/' || '*' && o[i] == '/' || '*'){
        return 1;
    }
    else if(s[a] == '+' || '-' && o[i] == '+' || '-'){
        return 1;
    }

    else{
        return 0;
    }
}

int main(){
    char arr[20];
    int topstack = -1;
    int toppost = -1;
    cout<<"Enter the expression";
    cin>>arr;
    int len = strlen(arr);
    char stack[len], postfix[len];

    for(int i =0; i< len;i++){
        if(arr[i]>48 && arr[i]<58){
            toppost++;
            postfix[toppost] = arr[i];
        }
        else if(arr[i]=='(')
        {
            topstack++;
            stack[topstack];
        }
        else if(arr[i]=')'){
            while(stack[topstack]!='('){
                toppost++;
                postfix[toppost]=stack[topstack];
                topstack--;
            }
            topstack--;
        }
        else{
            int prec = checkp(stack,arr,topstack,i);
            if (prec == 1){
                toppost++;
                postfix[toppost] = stack[topstack];
                stack[topstack] = arr[i];
            }
            else{
                topstack++;
                stack[topstack] = arr[i];
            }
        }

    }

    len = strlen(postfix);
    cout<<"\nExpression: \n"<<endl;
    for(int i=0;i<len;i++){
        cout<<postfix[i];
    }
}

