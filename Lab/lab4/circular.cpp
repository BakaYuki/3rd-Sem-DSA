#include <iostream>
#include <malloc.h>

using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node *pfirst = NULL, *pnew, *pthis, *ptemp, *plast;
int count = 0;

void create(){
    pnew = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter data for new node\n";
    cin>>pnew->data;
    pnew->next = NULL;
    count++;
}

void insertion_beg(){
    if(pfirst==NULL){
        pfirst = pnew;
        plast = pnew;
        pfirst->next = pfirst;
        plast->next = pfirst;
    }
    else{
        pnew->next=pfirst;
        pfirst = pnew;
    }
}

void insertion_end(){
    if(pfirst==NULL){
        pfirst = pnew;
        pfirst->next = plast;
    }
    else{
        pthis = pfirst;
        while(pthis->next!=NULL){
            pthis = pthis->next;
        }
        plast = pnew;
        pthis->next=plast;
    }
}

void insertion_specified(){
    int loc;
    char ch;
    cout<<"Enter node number\n";
    cin>>loc;

    if (loc > count){
        cout<<"Invalid node\n";
        return;
    }

    cout<<"Enter after specifed node? Y / N\n";
    cin>>ch;
    ch = toupper(ch);
    create();

    if ( ch == 'Y'){
        if(loc == count){
            insertion_end();
            return;
        }
        pthis = pfirst;
        for(int i = 1 ; i< loc ;i++){
            pthis = pthis->next;
        }
        ptemp = pthis->next;
        pthis->next = pnew;
        pnew->next = ptemp;
    }
    else{
        if(loc == 0){
            insertion_beg();
            return;
        }
        pthis = pfirst;
        for(int i = 1 ; i< loc-1 ;i++){
            pthis = pthis->next;
        }
        ptemp = pthis->next;
        pthis->next = pnew;
        pnew->next = ptemp;
    }
}

void deletion_beg(){
    if(pfirst == NULL){
        cout<<"The List is empty There is nothing to delete";
    }
    else if(pfirst->next == NULL){
        cout<<"Delete data is: "<<pfirst->data<<endl;
        free(pfirst);
        count--;
        pfirst = NULL;
    }
    else{
        ptemp = pfirst->next;
        cout<<"Delete data is "<<pfirst->data<<endl;
        free(pfirst);
        pfirst = ptemp;
        count--;
    }

}

void deletion_end(){
    if(pfirst == NULL){
        cout<<"The List is empty There is nothing to delete";
    }
    else if(pfirst->next == NULL){
        cout<<"Delete data is "<<pfirst->data<<endl;
        free(pfirst);
        pfirst = NULL;
        count--;
    }
    else{
        pthis = pfirst;
        while(pthis->next->next!=NULL){
            pthis = pthis->next;
        }
        cout<<"Deleted data is "<<pthis->next->data<<endl;
        free(pthis->next);
        count--;
        pthis->next = NULL;
    }

}

void deletion_specified(){
    int loc;
    cout<<"Enter node number to be deleted\n";
    cin>>loc;

    if (loc > count){
        cout<<"Invalid node\n";
        return;
    }
    pthis = pfirst;
    for(int i = 1; i< loc - 1; i++){
        pthis = pthis->next;
    }
    ptemp = pthis->next->next;
    free(pthis->next);
    pthis->next=ptemp;
    count--;

}
void display(){
    
    cout<<"Data in List are: \n";
    pthis = pfirst;
    if(pthis == NULL){
        cout<<"List is empty\n";
        return;
    }
    cout<<(pthis->data)<<"\t";
    pthis = pthis->next;
    while(pthis != plast->next){

        cout<<(pthis->data)<<"\t";
        pthis = pthis->next;
    }
    cout<<endl;
}
int main(){
    int a=0;
    
    while(a!=8){
        cout<<"\nChoose an option\n";
        cout<<"1. Insertion at beginning of List\n";
        cout<<"2. Insertion at end of List\n";
        cout<<"3. Insertion at specified node\n";
        cout<<"4. Deletion at beginning\n";
        cout<<"5. Deletion at end\n";
        cout<<"6. Deletion of specified node\n";
        cout<<"7. Display all data in List\n";
        cin>>a;
        switch(a){
            case 1:
                create();
                insertion_beg();
                break;
            
            case 2:
                create();
                insertion_end();
                break;
            
            case 3:
                insertion_specified();

                break;
            case 4:
                deletion_beg();
                break;
            
            case 5:
                deletion_end();
                break;
            
            case 6:
                deletion_specified();
                break;
            case 7:
                display();
                break;
        }
    }
}