#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *next, *prev;
};
struct node  *pnew, *pthis, *phead, *ptemp;
int count = 0;
void create(){
    pnew = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter data for new node\n";
    cin>>pnew->data;
    pnew->next = NULL;
    count++;
}

void insertion_beg(){
    if(phead->next==phead){
        pnew->next = phead;
        pnew->prev = phead;
        phead->next = pnew;
        phead->prev = pnew;
    }
    else{
        pthis = phead->next;
        pnew->next = pthis;
        pthis->prev = pnew;
        pnew->prev = phead;
        phead->next = pnew;
    }
}

void insertion_end(){
    if(phead->next==phead){
        pnew->next = phead;
        pnew->prev = phead;
        phead->next = pnew;
        phead->prev = pnew;
    }
    else{
        pthis = phead->prev;
        pthis->next = pnew;
        pnew->next = phead;
        phead->prev = pnew;
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
        pthis = phead->next;
        for(int i = 1 ; i< loc ;i++){
            pthis = pthis->next;
        }
        ptemp = pthis->next;
        pthis->next = pnew;
        pnew->next = ptemp;

    }
    else{
        if(loc == 1){
            insertion_beg();
            return;
        }
        pthis = phead->next;
        for(int i = 1 ; i< loc;i++){
            pthis = pthis->next;
        }
        ptemp = pthis->prev;
        ptemp->next = pnew;
        pnew->next = pthis;
        pthis->prev = pnew;
    }
}

void deletion_beg(){
    pthis = phead->next;
    if(pthis == phead){
        cout<<"The List is empty There is nothing to delete";
    }
    else if(pthis->next == phead){
        cout<<"Delete data is: "<<pthis->data<<endl;
        free(pthis);
        count--;
        phead->next = phead;
        phead->prev = phead;
    }
    else{
        cout<<"Delete data is "<<pthis->data<<endl;
        pthis = pthis->next;
        free(phead->next);
        phead->next = pthis;
        pthis->prev = phead;
        count--;
    }
}

void deletion_end(){
    pthis = phead->next;
    if(pthis == phead){
        cout<<"The List is empty There is nothing to delete";
    }
    else if(pthis->next == phead){
        cout<<"Delete data is: "<<pthis->data<<endl;
        free(pthis);
        count--;
        phead->next = phead;
        phead->prev = phead;
    }
    else{  
        pthis = phead->prev;      
        cout<<"Deleted data is "<<pthis->data<<endl;
        pthis = pthis->prev;
        free(phead->prev);
        count--;
        pthis->next = phead;
        phead->prev = pthis;
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
    pthis = phead->next;
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
    pthis = phead->next;
    if(pthis == phead){
        cout<<"List is empty\n";
    }
    else{
        while(pthis != phead){
            cout<<(pthis->data)<<"\t";
            pthis = pthis->next;
        }
        cout<<endl;
    }
}


int main(){
    phead = (struct node*)malloc(sizeof(struct node));
    phead->data = 0;
    phead->next = phead;
    phead->prev = phead;
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