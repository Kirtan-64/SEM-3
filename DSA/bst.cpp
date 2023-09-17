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

node* insertIntoBst(node* &root, int data)
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
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

bool searchBst(node* root, int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root -> data == data)
    {
        return true;
    }
    else if (root -> data < data)
    {
        return searchBst(root -> right, data);
    }
    else
    {
        return searchBst(root -> left, data);
    }
}

void inorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root ->left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void postorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

void preorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

int main()
{
    node* root = NULL;
    createBst(root);
    cout << searchBst(root,10) << endl;
    cout << searchBst(root,20) << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    return 0;
}