#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node()
    {
        this -> data = 0;
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

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

void inorder_iterative(node* curr)
{
    stack<node*> st;
    while (true)
    {
        if(curr != NULL){
            st.push(curr);
            curr = curr -> left;
        }
        else
        {
            if(st.empty()){break;}
            curr = st.top();
            cout << curr -> data << " ";
            st.pop();
            curr = curr -> right;
        }
    }

}

void preorder_iterative(node* root)
{
    if (root == NULL)
        return;
 
    stack<node*> st;
 
    // start from root node (set current node to root node)
    node* curr = root;
 
    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL) {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL) {
            cout << curr->data << " ";
 
            if (curr->right)
                st.push(curr->right);
 
            curr = curr->left;
        }
 
        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
        }
    }
}

void postorder_iterative(node* root)
{
    stack<node*> st;
    while (true) {
        while (root) {
            st.push(root);
            st.push(root);
            root = root->left;
        }
        if (st.empty())
            break;
        root = st.top();
        st.pop();
        if (!st.empty() && st.top() == root)
            root = root->right;
        else {
            cout << root -> data << " ";
            root = NULL;
        }
    }
}

int main()
{
    node* root = NULL;
    root = buildTree(root); //1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
    cout << "Inorder:" << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder: " << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder: " << endl;
    postorder(root);
    cout << endl;
    cout << "Inorder in iterative way:" << endl;
    inorder_iterative(root);
    cout << endl;
    cout << "Inorder in iterative way: " << endl;
    preorder_iterative(root);
    cout << endl;
    cout << "Postorder iterative: " << endl;
    postorder_iterative(root);
    cout << endl;
    return 0;
}