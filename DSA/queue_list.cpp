#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node()
    {
        this -> data = 0;
        this -> next = NULL;
    }

    node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

class queue
{
    public:
    node* front;
    node* rear;
    int size;
    int count;

    queue()
    {
        this -> front = NULL;
        this -> rear = NULL;
        size = 1000;
        count = 0;
    }

    queue(int size)
    {
        this -> front = NULL;
        this -> rear = NULL;
        this -> size = size;
        count = 0;
    }
    void enqueue(int data)
    {
        if(count == size)
        {
            cout << "List is full!" << endl;
        }
        else
        {
            if(rear == NULL)
            {
               rear = new node(data);
               front = rear;
               count++;
            }
            else
            {
                node* New = new node(data);
                rear -> next = New;
                count++;
            }
        }
    }

    void dequeue()
    {
        if(rear == NULL)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            if(front == rear)
            {
                delete(front);
                front = NULL;
                rear = NULL;
                count--;
            }
            else
            {
                node* tmp = front;
                front = front -> next;
                delete(tmp);
                count--;
            }
        }
    }
    void display()
    {
        if(rear == NULL)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            node* tmp = front;
            while(tmp != NULL)
            {
                cout << tmp -> data << " ";
                tmp = tmp -> next;
            }
            cout << endl;
        }
    }
};

int main()
{
    queue q(3);
    q.enqueue(1);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    return 0;
}