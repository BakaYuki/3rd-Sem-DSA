#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node
{
    int data;
    struct node *lchild, *rchild;
}*pthis, *pnew, *root, *ppthis;
// int loc, count=0;
void create()
{
    pnew=(struct node*)malloc(sizeof(struct node));
    cout<<"Enter data to insert:\n";
    cin>>pnew->data;
    pnew->lchild=NULL;
    pnew->rchild=NULL;
    // count++;
}

void inorder(struct node *p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        cout<<"\t"<<p->data<<"\n";
        inorder(p->rchild);
    }
}

void preorder(struct node *p)
{
    if(p!=NULL)
    {
        cout<<"\t"<<p->data<<"\n";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(struct node *p)
{
    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<"\t"<<p->data<<"\n";
    }
}

void search(struct node *p)
{
    int data;
    cout<<"Enter data to be searched:\n";
    cin>>data;
        p=root;
        while(p!=NULL)
        {
            if(data<p->data)
            {
                p=p->lchild;
            }
            else if(data>p->data)
            {
                p=p->rchild;
            }
            else
            {
                cout<<"Data Found\n";
                break;
            }
        }
        if(p==NULL)
        {
            cout<<"Data Not Found\n";
        }
}

int main()
{
    int n=0;
    while(n!=6)
    {
        cout<<"Enter your choice:\n 1.Create Binary Search Tree\n 2.Inorder Tree Traversal\n 3.Pre-order Tree Traversal\n 4.Post-order Tree Traversal\n 5.Search\n 6.Exit\n";
        cin>>n;

        switch(n)
        {
            case 1:
            root = (struct node*)malloc(sizeof(struct node));
            root->data=NULL;
            root->lchild=NULL;
            root->rchild=NULL;
            opt1:
            create();
            if(root->data==NULL)
            {
                root=pnew;
            }
            else
            {
                pthis=root;
                while(pthis!=NULL)
                {
                    ppthis=pthis;
                    if(pnew->data<pthis->data)
                    {
                        pthis=pthis->lchild;
                        if(pthis==NULL)
                        {
                            ppthis->lchild=pnew;
                        }
                    }
                    else if(pnew->data>pthis->data)
                    {
                        pthis=pthis->rchild;
                        if(pthis==NULL)
                        {
                            ppthis->rchild=pnew;
                        }
                    }
                    else
                    {
                        cout<<"Duplicate node\n";
                    }   
                }
            }
            char ch;
            cout<<"Enter new node? [y/n]\n";
            cin>>ch;
            if(ch=='y')
            {
                goto opt1;
            }
            break;

            case 2:
            inorder(root);
            break;

            case 3:
            preorder(root);
            break;

            case 4:
            postorder(root);
            break;

            case 5:
            search(root);
            break;
        }
    }
}