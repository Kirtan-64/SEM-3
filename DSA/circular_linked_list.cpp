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

void insertAtFront(node* &head, int data)
{
    if(head == NULL)
    {
        head = new node(data);
        head -> next = head;
    }
    else
    {
        node* tmp = head;
        while(tmp -> next != head)
        {
            tmp = tmp -> next;
        }
        node* New = new node(data);
        New -> next = head;
        tmp -> next = New;
        head = New;
    }
}

void deleteAtEnd(node* &head)
{
    if(head == NULL)
    {
        cout << "List is empty!!" << endl;
    }
    else if(head -> next == head)
    {
        delete(head);
        head = NULL;
    }
    else
    {
        node* tmp = head;
        while((tmp -> next) -> next != head)
        {
            tmp = tmp -> next;
        }
        delete(tmp -> next);
        tmp -> next = head;
    }
}

void display(node* head)
{
    if(head == NULL)
    {
        cout << "List is empty!!" << endl;
    }
    else
    {
        node* tmp = head;
        while(tmp -> next != head)
        {
            cout << tmp -> data << " ";
            tmp = tmp -> next;
        }
        cout << tmp -> data << endl;
    }
}

int main()
{
    node* head = NULL;
    insertAtFront(head,2);
    insertAtFront(head,1);
    display(head);
    deleteAtEnd(head);
    display(head);
    insertAtFront(head,0);
    display(head);
    return 0;
}