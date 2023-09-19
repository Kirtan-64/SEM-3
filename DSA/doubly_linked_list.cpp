#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node()
    {
        this -> data = 0;
        this -> next = NULL;
        this -> prev = NULL;
    }

    node(int data)
    {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void insertAtEnd(node* &head, int data)
{
    if(head == NULL)
    {
        head = new node(data);
    }
    else
    {
        node* tmp = head;
        while(tmp -> next != NULL)
        {
            tmp = tmp -> next;
        }
        node* New = new node(data);
        tmp -> next = New;
        New -> prev = tmp;
    }
}

void insertAtFront(node* &head, int data)
{
    if(head == NULL)
    {
        head = new node(data);
    }
    else
    {
        node* New = new node(data);
        New -> next = head;
        head -> prev = New;
        head = New;
    }
}

int nodeCount(node* head)
{
    if(head == NULL)
    {
        cout << "List is empty!!" << endl;
        return 0;
    }
    else
    {
        int count = 0;
        node* tmp = head;
        while(tmp != NULL)
        {
            count++;
            tmp = tmp -> next;
        }
        cout << "Nodes: " << count << endl;
        return count;
    }
}

void deleteAtFront(node* &head)
{
    if(head == NULL)
    {
        cout << "List is empty!!" << endl;
    }
    else if(head -> next == NULL)
    {
        delete(head);
        head = NULL;
    }
    else
    {
        node* tmp = head;
        tmp = tmp -> next;
        delete(head);
        head = tmp;
        head -> prev = NULL;
    }
}

void insertAfter(node* &head, int target, int data)
{
    if(head == NULL)
    {
        cout << "List is empty!! " << endl;
    }
    else if(head -> next == NULL)
    {
        if(head -> data == target)
        {
            node* New = new node(data);
            head -> next = New;
            New -> prev = head;
        }
        else
        {
            cout << "Target not in list!!" << endl;
        }
    }
    else
    {
        node* tmp = head;
        while(true)
        {
            if(tmp -> data == target)
            {
                break;
            }
            if(tmp == NULL)
            {
                break;
            }
            tmp = tmp -> next;
        }
        if(tmp == NULL)
        {
            cout << "Target not in list!!" << endl;
        }
        else
        {
            node* New = new node(data);
            New -> prev = tmp;
            New -> next = tmp -> next;
            if(tmp -> next != NULL){
                (tmp -> next) -> prev = New;
            }
            tmp -> next = New;
        }
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
        while(tmp != NULL)
        {
            cout << tmp -> data << " ";
            tmp = tmp -> next;
        }
        cout << endl;
    }
}

node* concatenate(node* head1,node* head2)
{
    if(head1 == NULL && head2 == NULL)
    {
        return NULL;
    }
    else if(head1 == NULL)
    {
        return head2;
    }
    else if(head2 == NULL)
    {
        return head1;
    }
    else
    {
        node* tmp = head1;
        while(tmp -> next != NULL)
        {
            tmp = tmp -> next;
        }
        tmp -> next = head2;
        head2 -> prev = tmp;
        return head1;
    }
}

int main()
{
    node* head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    display(head);
    insertAtFront(head, 0);
    display(head);
    nodeCount(head);
    deleteAtFront(head);
    display(head);
    insertAfter(head, 2, 3);
    display(head);
    node* head1 = NULL;
    insertAtFront(head1, 2);
    insertAtEnd(head1,3);
    insertAtFront(head1, 1);
    head1 = concatenate(head, head1);
    display(head1);
    return 0;
}