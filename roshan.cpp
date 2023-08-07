#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
using namespace std;
class books{
    int bookcode;
    char bookname[20],author[40];
public:
friend class adminis;
void addbook(){
    cout<<"Enter the name of the book: ";
    cin>>bookname;
    cout<<"author name: ";
    cin>>author;
    cout<<"Enter the code for the book: ";
    cin>>bookcode;
}
void deletebook(){

}
};
class adminis
{
    int   year, code[7],count=0;
   char book[7][20],author[7][40];
    char phone[100],roll[15], faculty[100], name[100], surname[100], address[100],pass[100];
 public:
    void addmem();
   char* getpass(){
        return(pass);
    }
    char* getroll()
    {
        return (roll);
    }
    char* getname()
    {
        return (name);
    }
    int getcount(){
        return (count);
    }
    adminis issue(int x);
    adminis returnin();
    void display()
    {
        system("cls");
        cout << "\n\n\t\t _____________________________________________" << endl;
        cout << "\t\t|          KHWOPA ENGINEERING COLLLEGE          |" << endl;
        cout << "\t\t|               liwali-4, Bhaktapur             |" << endl;
        cout << "\t\t|                                               |" << endl;
        cout << "\t\t|             Student Library Detail            | " << endl;
        cout << "\t\t|-----------------------------------------------|" << endl;
        cout << "\t\t|"
             << "Name-" << name << ' ' << surname << "\t\t\t\t|"<<endl;
        cout << "\t\t|"
             << "Roll-" << roll << "\t\t"
             << "Address-" << address << "\t\t|"<<endl;
        cout << "\t\t|"
             << "Year-" << year << "\t\t"
             << "Faculty-" << faculty << "\t\t|"<<endl;
        cout << "\t\t|"
             << "phone-" << phone << "\t\t\t\t|"<<endl;
        cout << "\t\t|-----------------------------------------------|" << endl;
        cout << "\t\t|   Book code  |Book name      |  Author        |" << endl;
        cout << "\t\t|--------------|---------------|----------------|" << endl;
        cout <<"\t\t|\t" << code << "\t|" << book << "\t |\t" << author << " \t |" << endl;
        cout << "\t\t|_______________________________________________|" << endl;
    }
};
void adminis::addmem()
{
    cout << "Enter name and surname: ";
    cin >> name >> surname;
    cout << "Enter roll no and mobile number: ";
    cin >> pass >> phone;
    cin.ignore();
    strcpy(roll,pass);
    while((strlen(phone)!=10) && phone[0]!=9){
        cout<<"Entered number is incorrect & try again: "<<endl<<"phone: ";
    cin>>phone;
    } 
    year = (2000 + (stoi(roll) / 10000));
    cout << "faculty and address: ";
    cin >> faculty >> address;
}
adminis adminis::issue(int x)
{

    if (x == 1)
    {
    }
    
}
adminis adminis::returnin()
{
    adminis d;
    strcpy(d.name,name);
    strcpy(d.surname,surname);
    strcpy(d.faculty,faculty);
    strcpy(d.roll,roll);
    strcpy(d.phone,phone);
    d.year = year;
    strcpy(d.address,address);
    d.code = 0;
    return d;
}
int main()
{
    int d = 0, b, n,t, x, i, m = 0,code;
   char r[15],username[100],password[100];
    char k,ch,cg;
    adminis a[100], c, e, l;
    books b[100];
    cout<< "***********Welcome To Library**************" << endl;
    getch();
    login:
    system("cls");
         cout<< "Enter credential for logging in !";
    cout << endl
         << "Enter username:";
    cin >> username;
    cout << "Enter password:";
    cin >> password;
    if (strcmp(username,"admin")==0 && strcmp(password,"1234")==0)
    {m++;
    start:
    system("cls");
        cout << "1. Add member \n 2. Access member \n 3. Delete member \n 4. Add book \n 5. Delete book \n 6. signout: ";
        cin >> b;
        switch (b)
        {
        case 1:{
            cout << "Enter number student to be added:";
            cin >> n;
            fstream fout("data.txt", ios::in|ios::out|ios::app);
             for (i = 0; i < n; i++)
            {
                a[i].addmem();
                fout.write((char *)&a[i], sizeof(adminis));
            }
            fout.close();
            
             
            goto start;}
        case 2:
        {
        leb:
        system("cls");
            cout << "Enter roll no of the student:";
            cin >> r;
            ifstream fi("data.txt");
            fi.seekg(0,ios::end);
            d=fi.tellg()/sizeof(adminis);
            fi.seekg(0, ios::beg);
            for(i=0;i<d;i++){
                fi.read((char *)&a[i], sizeof(adminis));}
                 fi.seekg(0, ios::beg);
            for(i=0;i<d;i++){
                fi.read((char *)&l, sizeof(adminis));
                t=0;
                 if (strcmp(r,l.getroll())==0)
                {
                    c = l;
                    c.display();
                    x = i;
                t++;
                }
            
            }
            fi.close();
            if(t==0){
                cout<<"roll not found"<<endl;
                goto leb;
            }
            else{
                ac:
                system("cls");
            cout << endl<< "Enter 'a' for issuing book , 'b' for retruning book & except a,b for login:";
            cin >> k;
            switch (k)
            {
            case 'a':
            {
                if(c.getcount()>=7){
                    cout<<"Already issued 7 books!!";
                    getch();
                    cout<<"Do you to return ? ";
                    cin>>cg;
                   if(cg=='y'||cg=='Y'){
                    goto ac;
                   }
                   else{
                    goto leb;
                   }}
                   else{
                    cd:
                system("cls");
    cout << endl;
    cout << "Enter book code:";
    cin >> code;
    if(compare code with ){
                c.issue(c.getcount());
                ofstream fout("data.txt", ios::out);
                fout.seekp(0, ios::beg);
                for (int i = 0; i < d; i++)
                {
                    if (i == x)
                    {
                        a[i] = c;
                        a[i].display();
                    }
                    fout.write((char *)&a[i], sizeof(a[i]));
                }
                fout.close();}
                else
    {
        system("cls");
        cout << "Not available, enter another:" << endl;
        goto cd;
    }
                char ch;
                cout << "Enter y for accessing another member ,other for sign out:";
                cin >> ch;
                if (ch == 'y')
                {
                    goto leb;
                }
                else
                {
                    goto login;
                }}
                
                break;
            }
            case 'b':
            {system("cls");
                e = c.returnin();
                ofstream fo("data.txt");
                fo.seekp(0, ios::beg);
                for ( i = 0; i < d; i++)
                {
                    if (i == x)
                    {
                        a[i] = e;
                        a[i].display();
                    }
                    fo.write((char *)&a[i], sizeof(a[i]));
                }
                fo.close();
                char p;
                cout << "Enter y for accessing another member ,other for sign out:";
                cin >> p;
                if (p == 'y')
                {
                    goto leb;
                }
                else
                {
                    goto login;
                }
            break;}
            default:{
                goto login;}
            }}
        break;
        }
        case 4:{
            cout << "Enter number books to be added:";
            cin >> n;
            fstream fout("book.txt", ios::in|ios::out|ios::app);
             for (i = 0; i < n; i++)
            {
                b[i].addbook();
                fout.write((char *)&b[i], sizeof(books));
            }
            fout.close();  
            goto start;
        }
        case 6:
            goto login;
            break;
        default:
            cout << "sorry";
            goto start;
        }
    }
    else{
        ifstream fin("data.txt");
        fin.seekg(0,ios::end);
            d=fin.tellg()/sizeof(adminis);
        fin.seekg(0, ios::beg);
        for (i = 0; i < d; i++)
        {
            fin.read((char *)&a[i], sizeof(a[i]));
            if (strcmp(username,a[i].getname())==0 && strcmp(password,a[i].getpass())==0)
            {
                cout<<"Welcome "<<a[i].getname()<<" !!"<<endl;
                getch();
                a[i].display();
                m++;
                cout << "Enter a key to logout:";
                getch();
                goto login;
            }
        }
        fin.close();
    if (m == 0)
    {
        cout << "wrong credential!!";
        goto login;
    }
    }
    return 0;
}