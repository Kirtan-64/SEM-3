#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    node()
    {
        this -> data = 0;
        this -> next = NULL;
    }
};

class stack
{
    public:
    node* top;
    node* head;
    int size;
    int count;

    stack(int size)
    {
        this -> size = size;
        this -> count = 0;
        top = NULL;
        head = NULL;
    }

    stack()
    {
        this -> size = 1000;
        this -> count = 0;
        top = NULL;
        head = NULL;
    }

    void push(int data)
    {
        if(top == NULL)
        {
            top = new node(data);
            head = top;
            count++;
        }
        else if(count == size)
        {
            cout << "Stack overflow!!" << endl;
        }
        else
        {
            node* New = new node(data);
            top -> next = New;
            top = top -> next;
            count++;
        }
    }

    void pop()
    {
        if(top == NULL)
        {
            cout << "Stack is empty!!" << endl;
        }
        else if(top == head)
        {
            delete(top);
            top = NULL;
            head = NULL;
            count--;
        }
        else
        {
            node* tmp = head;
            while(tmp -> next != top)
            {
                tmp = tmp -> next;
            }
            delete(top);
            top = tmp;
            top -> next = NULL;
            count--;
        }
    }

    void display()
    {
        if(top == NULL)
        {
            cout << "Stack is empty!!" << endl;
        }
        else if (top == head)
        {
            cout << "stack: " << endl;
            cout << top -> data << endl;
        }
        else
        {
            cout << "stack:" << endl;
            node* tmp = head;
            while(tmp != top)
            {
                cout << tmp -> data << " ";
                tmp = tmp -> next;
            }
            cout << top -> data;
            cout << endl;
        }
    }
};

int main()
{
    stack st(3);
    st.push(1);
    st.display();
    st.push(2);
    st.push(3);
    st.push(4);
    st.display();
    st.pop();
    st.display();
    st.pop();
    st.display();
    st.pop();
    st.display();
    st.pop();
    return 0;
}