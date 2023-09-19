#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

};

void insertionAtHead(Node* &head, int data)
{
    Node* tmp = new Node(data);
    tmp -> next = head;
    head = tmp;
}

void insertionAtEnd(Node* &head, int data)
{
    Node* New = new Node(data);
    Node *tmp = head;
    while(tmp -> next != NULL)
    {
        tmp = tmp -> next;
    }
    tmp -> next = New;
}

void printList(Node* &head)
{
    Node *tmp = head;
    while(tmp != NULL)
    {
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

void insertAtPos(Node* &head, int pos, int data)
{
    int i = 1;
    Node* New = new Node(data);
    Node* tmp = head;
    while(i < pos - 1)
    {
        tmp = tmp-> next;
        i++;
    }
    New -> next = tmp -> next;
    tmp -> next = New;
}

void insertAfterData(Node* head, int d, int data)
{
    Node* New = new Node(data);
    Node *tmp = head;
    while (tmp -> data != d)
    {
        tmp = tmp -> next;
    }
    New -> next = tmp -> next;
    tmp -> next = New;
}

void deleteHead(Node* &head)
{
    Node* tmp = head -> next;
    if (tmp -> next == NULL)
    {
        cout << "Only one node present!!" << endl;
    }
    else{
        delete(head);
        head = tmp;
    }
}

void deleteTail(Node* &head)
{
    if (head -> next == NULL)
    {
        cout << "only one node present!!" << endl;
    }
    else
    {
        Node* tmp = head;
        while ((tmp -> next) -> next != NULL)
        {
            tmp = tmp -> next;
        }
        Node *tmp1 = tmp -> next;
        tmp -> next = NULL;
        delete(tmp1);
    }
}

void deleteAtPos(Node* &head, int pos)
{
    if (head -> next == NULL)
    {
        cout << "only one node present!!!" << endl;
    }
    else
    {
        Node * tmp = head;
        int i = 1;
        while (i < pos - 1)
        {
            tmp = tmp -> next;
        }
        Node* tmp1 = tmp -> next;
        tmp -> next = tmp1 -> next;
        delete(tmp1);
    }
}

void deleteAtValue(Node* &head, int data)
{
    Node* tmp = head;
    while ((tmp -> next)-> data != data)
    {
        tmp = tmp -> next;
    }
    Node* tmp1 = tmp -> next;
    tmp -> next = tmp1 -> next;
    delete(tmp1);
}

Node* reverseList(Node* head)
{
    Node* rehead = new Node(head -> data);
    Node* tmp = head -> next;
    while(tmp != NULL)
    {
        insertionAtHead(rehead, tmp -> data);
        tmp = tmp -> next;   
    }
    return rehead;
}

int main()
{
    Node *head = new Node(10);
    printList(head);
    insertionAtHead(head, 9);
    insertionAtHead(head, 8);
    printList(head);
    insertionAtEnd(head, 11);
    printList(head);
    insertAtPos(head, 2, 1);
    printList(head);
    insertAfterData(head, 1, 5);
    printList(head);
    deleteHead(head);
    printList(head);
    deleteTail(head);
    printList(head);
    deleteAtPos(head, 2);
    printList(head);
    deleteAtValue(head, 9);
    printList(head);
    Node* rev = reverseList(head);
    printList(rev);
    return 0;
}