#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node()
    {
        data = 0;
        this -> left = NULL;
        this -> right = NULL;
    }

    node(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* insertIntoBst(node* root, int data)
{
    if(root == NULL)
    {
        node* New = new node(data);
        return New;
    }

    if(data < root -> data)
    {
        root -> left = insertIntoBst(root -> left, data);
    }
    else
    {
        root -> right = insertIntoBst(root -> right, data);
    }
    return root;
}

void createBst(node* &root)
{
    int data;
    cin >> data;
    while(data != -1)
    {
        insertIntoBst(root, data);
        cin >> data;
    }
}



int main()
{
    node* root = NULL;
    createBst(root);
    return 0;
}