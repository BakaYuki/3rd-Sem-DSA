#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node *next, *prev;
};

struct node *pnew, *pthis, *phead, *ptemp;
int count = 0;

void create() {
    pnew = new node;
    cout << "Enter data for new node\n";
    cin >> pnew->data;
    pnew->next = nullptr;
    count++;
}

void insertion_beg() {
    if (phead->next == nullptr) {
        pnew->next = phead;
        pnew->prev = phead;
        phead->next = pnew;
        phead->prev = pnew;
    } else {
        pthis = phead->next;
        pnew->next = pthis;
        pthis->prev = pnew;
        pnew->prev = phead;
        phead->next = pnew;
    }
}

void insertion_end() {
    if (phead->prev == nullptr) {
        pnew->next = phead;
        pnew->prev = phead;
        phead->next = pnew;
        phead->prev = pnew;
    } else {
        pthis = phead->prev;
        pthis->next = pnew;
        pnew->next = phead;
        phead->prev = pnew;
    }
}

void insertion_specified() {
    int loc;
    char ch;
    cout << "Enter node number\n";
    cin >> loc;

    if (loc > count) {
        cout << "Invalid node\n";
        return;
    }

    cout << "Enter after specified node? Y / N\n";
    cin >> ch;
    ch = toupper(ch);
    create();

    if (ch == 'Y') {
        if (loc == count) {
            insertion_end();
            return;
        }
        pthis = phead->next;
        for (int i = 1; i < loc; i++) {
            pthis = pthis->next;
        }
        ptemp = pthis->next;
        pthis->next = pnew;
        pnew->next = ptemp;

    } else {
        if (loc == 0) {
            insertion_beg();
            return;
        }
        pthis = phead->next;
        for (int i = 1; i < loc - 1; i++) {
            pthis = pthis->next;
        }
        ptemp = pthis->next;
        pthis->next = pnew;
        pnew->next = ptemp;
    }
}

void deletion_beg() {
    pthis = phead->next;
    if (pthis == phead) {
        cout << "The List is empty. There is nothing to delete.";
    } else if (pthis->next == phead) {
        cout << "Delete data is: " << pthis->data << endl;
        delete pthis;
        count--;
        phead->next = nullptr;
        phead->prev = nullptr;
    } else {
        cout << "Delete data is " << pthis->data << endl;
        pthis = pthis->next;
        delete phead->next;
        phead->next = pthis;
        pthis->prev = phead;
        count--;
    }
}

void deletion_end() {
    pthis = phead->next;
    if (pthis == phead) {
        cout << "The List is empty. There is nothing to delete.";
    } else if (pthis->next == phead) {
        cout << "Delete data is: " << pthis->data << endl;
        delete pthis;
        count--;
        phead->next = nullptr;
        phead->prev = nullptr;
    } else {
        pthis = phead->prev;
        pthis = pthis->prev;
        cout << "Deleted data is " << pthis->data << endl;
        delete phead->prev;
        count--;
        pthis->next = phead;
        phead->prev = pthis;
    }
}

void deletion_specified() {
    int loc;
    cout << "Enter node number to be deleted\n";
    cin >> loc;
    if (loc > count) {
        cout << "Invalid node\n";
        return;
    }
    pthis = phead->next;
    for (int i = 1; i < loc - 1; i++) {
        pthis = pthis->next;
    }
    ptemp = pthis->next->next;
    delete pthis->next;
    pthis->next = ptemp;
    count--;
}

void display() {
    cout << "Data in List are:\n";
    pthis = phead->next;
    if (pthis == phead) {
        cout << "List is empty.\n";
    } else {
        while (pthis != phead) {
            cout << pthis->data << "\t";
            pthis = pthis->next;
        }
    }
    cout << endl;
}

int main() {
    phead = new node;
    phead->data = 0;
    phead->next = nullptr;
    phead->prev = nullptr;

    int a = 0;
    while (a != 8) {
        cout << "\nChoose an option:\n";
        cout << "1. Insertion at the beginning of the List\n";
        cout << "2. Insertion at the end of the List\n";
        cout << "3. Insertion at a specified node\n";
        cout << "4. Deletion at the beginning\n";
        cout << "5. Deletion at the end\n";
        cout << "6. Deletion of a specified node\n";
        cout << "7. Display all data in the List\n";
        cin >> a;
        switch (a) {
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

    delete phead;

    return 0;
}
