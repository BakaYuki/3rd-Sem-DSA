#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node
{
    int data;
    struct node *pnext;
}*pfirst = NULL,*pthis,*pnew,*ptemp,*plast;

int loc, count=0;

void create_node()
{
    pnew=(struct node*)malloc(sizeof(struct node));
    cout<<"Enter data to insert:\n";
    cin>>pnew->data;
    pnew->pnext=NULL;
    count++;
}

void insertion_beg()
{
    if(pfirst==NULL)
    {
        pfirst=pnew;
        plast=pnew;
        plast->pnext=pfirst;
    }
    else
    {
        pnew->pnext=pfirst;
        pfirst=pnew;
        plast->pnext=pfirst;
    }
}

void insertion_end()
{
    if(pfirst==NULL)
    {
        pfirst=pnew;
        plast=pnew;
        plast->pnext=pfirst;
    }
    else
    {
        // pthis=pfirst;
        // while(pthis->pnext!=pfirst)
        // {
            // pthis=pthis->pnext;
        // }
        // pthis->pnext=pnew;
        // pnew->pnext=pfirst; 
        plast->pnext=pnew;
        plast=pnew;
        plast->pnext=pfirst;
    }
}

void insertion_spe()
{
    int loc;
    char ans;
    cout<<"Enter location:"<<"\n";
    cin>>loc;
    if(loc>count)
    {
        cout<<"Invalid\n";
        return;
    }
    cout<<"Enter before or after[B/A]:"<<"\n";
    cin>>ans;
    ans = toupper(ans);
    create_node();

    if(ans=='B')
    {
        if(loc==0)
        {
            insertion_beg();
            return;
        }
        pthis=pfirst;
        for(int i=1;i<loc-1;i++)
        {
            pthis=pthis->pnext;
        }
        ptemp=pthis->pnext;
        pthis->pnext=pnew;
        pnew->pnext=ptemp;
    }
    else if(ans=='A')
    {
        if(loc==count)
        {
            insertion_end();
        }
        else
        {
            pthis=pfirst;
            for(int i=1;i<loc;i++)
            {
                pthis=pthis->pnext;
            }
            ptemp=pthis->pnext;
            pthis->pnext=pnew;
            pnew->pnext=ptemp;
        }
    }
    else
    {
        cout<<"Enter valid option:"<<"\n";
    }
}

void display()
{
    pthis=pfirst;
    if(pfirst==NULL)
    {
        pfirst=pnew;
        plast=pnew;
        pnew->pnext=pfirst;
        return;
    }
        cout<<"Data:"<<pthis->data<<"\n";
        pthis=pthis->pnext;
    while(pthis->pnext!=pfirst)
    {
        cout<<"Data:"<<pthis->data<<"\n";
        pthis=pthis->pnext;
    }
    cout<<"Data:"<<pthis->data<<"\n";
    // cout<<"plast"<<plast->data<<endl;
}

void deletion_beg()
{
    if(pfirst==NULL)
    {
        cout<<"List is empty"<<"\n";
    }
    else if(pfirst->pnext==plast)
    {
        cout<<"Deleted data:"<<pfirst->data<<"\n";
        free(pfirst);
        free(plast);
        count--;
        pfirst=NULL;
        plast=NULL;
    }
    else
    {
        cout<<"Deleted data:"<<pfirst->data<<"\n";
        ptemp=pfirst->pnext;
        free(pfirst);
        count--;
        pfirst=ptemp;
        plast->pnext=pfirst;
    }
}

void deletion_end()
{
    if(pfirst==NULL)
    {
        cout<<"List is empty"<<"\n";
    }
    else if(pfirst->pnext==plast)
    {
        cout<<"Deleted data:"<<pfirst->data<<"\n";
        free(pfirst);
        free(plast);
        count--;
        pfirst=NULL;
        plast=NULL;
    }
    else
    {
        pthis=pfirst;
        while(pthis->pnext!=plast)
        {
            pthis=pthis->pnext;
        }
        cout<<"Deleted data:"<<pthis->pnext->data<<"\n";
        free(plast);
        count--;
        plast=pthis;
        plast->pnext=pfirst;
        
    }
}

void deletion_spe()
{
    int loc;
    cout<<"Enter node number to be deleted\n";
    cin>>loc;

    if (loc > count)
    {
        cout<<"Invalid node\n";
        return;
    }
    pthis = pfirst;
    for(int i = 1; i< loc - 1; i++)
    {
        pthis = pthis->pnext;
    }
    ptemp = pthis->pnext->pnext;
    free(pthis->pnext);
    pthis->pnext=ptemp;

}

int main()
{
    int ch;
    while(ch != 8)
    {
        cout<<"Choose your option:\n 1.Insertion from beginning\n 2.Insertion fron end\n 3.Display\n 4.Deletion from beginning\n 5.Deletion from end\n 6.Insertion from specified\n 7.Deletion from specified\n 8.Exit\n";
        cin>>ch;

        switch(ch)
        {
            case 1:
                create_node();
                insertion_beg();
                break;

            case 2:
                create_node();
                insertion_end();
                break;

            case 3:
                display();
                break;

            case 4:
                deletion_beg();
                break;

            case 5:
                deletion_end();
                break;

            case 6:
                insertion_spe();
                break;

            case 7:
                deletion_spe();
                break;
        }
    }
}