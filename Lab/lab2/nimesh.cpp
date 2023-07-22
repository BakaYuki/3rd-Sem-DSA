#include <iostream>
#define MAX 5
using namespace std;
int main()
{
    int n;
    int queue[MAX];
    int rear = -1, front = -1;
    int data;
    bool quit{ false };
    while (!quit)
    {
        cout << "1 - Insert Data\n";
        cout << "2 - Out Data\n";
        cout << "3 - Display\n";

        cout << "Opt: ";
        cin >> n;
        switch (n)
        {
            case 1:
                if ((rear == MAX - 1 && front == 0) || front == rear + 1)
                {
                    cout << "queue is overflow\n";
                }
                else
                {
                    cout << "Data: ";
                    cin >> data;
                    rear = (rear + 1) % MAX;
                    if (front == -1)
                    {
                        front = 0;
                    }
                    queue[rear] = data;
                    cout << "data inserted!\n";
                }
                break;
            case 2:
                if (front == -1)
                {
                    cout << "queue is empty!\n";
                    break;
                }
                if (front == rear)
                {
                    cout << "dequeued element is: " << queue[front] << '\n';
                    front = -1;
                    rear = -1;
                }
                else
                {
                    cout << "dequeued element is: " << queue[front] << '\n';
                    front = (front + 1) % MAX;
                }
                break;
            case 3:
                int i = front;
                do
                {
                    cout << queue[i] << '\t';
                    i = (i + 1) % MAX;
                } while (i != rear);
                cout << queue[i] << '\t';
                cout << '\n';
                break;
        }
    }
    return 0;
}

 
