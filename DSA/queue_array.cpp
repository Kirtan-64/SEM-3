#include <iostream>
using namespace std;

class queue
{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    queue()
    {
        this -> front = -1;
        this -> rear = -1;
        size = 1000;
        arr = new int[size];
    }

    queue(int size)
    {
        this -> front = -1;
        this -> rear = -1;
        this -> size = size;
        arr = new int[size];
    }

    void enqueue(int data)
    {
        if(rear < size - 1)
        {
            rear++;
            arr[rear] = data;
        }
        else
        {
            cout << "Queue is full!!";
        }
    }

    void dqueue()
    {
        if(rear == front)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            front++;
        }
    }

    void display()
    {
        if (front == rear)
        {
            cout << "Queue is empty!!" << endl;
        }
        else
        {
            for(int i = front + 1; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;    
        }
    }
};


int main()
{
    queue q(10);
    q.enqueue(1);
    q.display();
    q.dqueue();
    q.display();
    q.dqueue();
    q.display();
    return 0;
}