#include <iostream>
#include <malloc.h>

using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node *pfirst =NULL, *pnew, *pthis, *ptemp, *plast;
//int count = 0;

void create(){
    pnew = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter data for new node\n";
    cin>>pnew->data;
    pnew->next = NULL;
   // count++;
}

void insertion_beg(){
    if(pfirst==NULL){
        pfirst = pnew;
        pfirst->next = pfirst;
        plast = pfirst;        
    }
    else{
        pnew->next = pfirst;
        pfirst = pnew;
        plast->next = pfirst;
    }
}

void insertion_end(){
    if(pfirst==NULL){
        pfirst = pnew;
        pfirst->next = pfirst;
        plast = pfirst;
    }
    else{
        plast->next = pnew;
        plast = pnew;
        plast->next = pfirst;
    }
}

void deletion_beg(){
    if(pfirst==NULL){
        cout<<"List is empty"<<endl;
    }
    else if(pfirst->next==pfirst){
        cout<<"Deleted data:"<<pfirst->data<<"\n";
        free(pfirst);
        free(plast);
     //   count--;
        pfirst=NULL;
        plast=NULL;
    }
    else{
        cout<<"Deleted data:"<<pfirst->data<<"\n";
        ptemp=pfirst->next;
        free(pfirst);
      //  count--;
        pfirst = ptemp;
        plast->next = pfirst;
    }
}

void deletion_end(){
    if(pfirst == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    else if(pfirst->next == pfirst){
        cout<<"Deleted data: "<<pfirst->data<<endl;
        free(pfirst);
        free(plast);
      //  count--;
        pfirst = NULL;
        plast = NULL;
    }
    else{
        pthis = pfirst;
        while(pthis->next!=plast)
        {
            pthis = pthis->next;
        }
        
        cout<<"Deleted datas:"<<pthis->next->data<<"\n";
        free(plast);
      //  count--;
        plast=pthis;
        plast->next=pfirst;
    }
}
void display(){
    
    pthis = pfirst;
    if(pthis == NULL){
        cout<<"List is empty\n";
        return;
    }
    cout<<"Data in List are: \n";
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
        cout<<"3. Deletion at beginning\n";
        cout<<"4. Deletion at end\n";
        cout<<"5. Display all data in List\n";
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
                deletion_beg();
                break;
            
            case 4:
                deletion_end();
                break;

            case 5:
                display();
                break;
        }
    }
}