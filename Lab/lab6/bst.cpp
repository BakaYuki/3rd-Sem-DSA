#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *lchild , *rchild;
};
struct node *root,*pthis,*ppthis,*pnew;

void create(){
    pnew = new node;
    cout << "Enter data for new node\n";
    cin >> pnew->data;
    pnew->rchild = NULL;
    pnew->lchild = NULL;
}

void inorder(struct node *p){
    if(p!=NULL){
        inorder(p->lchild);
        cout<<"\t"<<p->data;
        inorder(p->rchild);
    }
}

void postorder(struct node *p){
    if(p!=NULL){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<"\t"<<p->data;
    }
}

void preorder(struct node *p){
    if(p!=NULL){
        cout<<"\t"<<p->data;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void search(struct node *p){
    cout<<"Enter data to search"<<endl;
    int data;
    cin>>data;
    while(p!=NULL){
        if(data<p->data){
            p = p->lchild;
        }
        else if(data>p->data){
            p = p->rchild;
        }
        else{
            cout<<"Data is found"<<endl;
            break;
        }
    }
    if(p==NULL){
        cout<<"Data not found"<<endl;
    }
}
int main(){
    int c=0;


    while(c!=6){
        cout<<"\n1. Create Binary Search Tree"<<endl;
        cout<<"2. Inorder Tree Traversal"<<endl;
        cout<<"3. Postorder Tree Traversal"<<endl;
        cout<<"4. Preorder Tree Traversal"<<endl;
        cout<<"5. Search Data in Tree"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>c;
    
        if(c == 1){
            char ch = 'y';
            root = (struct node*)malloc(sizeof(struct node));
            root->data = NULL;
            root->rchild = NULL;
            root->lchild = NULL;
            
            while(ch!='n'){
                create();
                if(root->data == NULL){
                    root = pnew;
                }
                else{
                    pthis = root;
                    while(pthis!=NULL){
                        ppthis = pthis;
                        if(pnew->data <pthis->data){
                            pthis = pthis->lchild;
                            if(pthis == NULL){
                                ppthis->lchild = pnew;
                            }
                        }
                        else if(pnew->data>pthis->data){
                            pthis = pthis->rchild;
                            if(pthis == NULL){
                                ppthis->rchild = pnew;
                            }
                        }
                        else{
                            cout<<"Data Already Present";
                        }
                    }
                }
                cout<<"\nEnter new data?\t";
                cin>>ch;
            }
        }
        else if(c == 2){
            cout<<"Inorder Traversal: \n";
            inorder(root);
        }

        else if(c==3){
            cout<<"Postorder Traversal: \n";
            postorder(root);
        }
        else if(c== 4){
            cout<<"Preorder Traversal: \n";
            preorder(root);
        }
        else if ( c== 5){
            search(root);
        }
        else if ( c== 6){
            exit(0);
        }
        else{
            cout<<"\nEnter valid option\n";
        }
    }
}