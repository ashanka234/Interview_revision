#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int d)
{
    Node *temp = new Node;
    temp->data = d;
    temp->left = temp->right = NULL;

    return temp;
}

bool isMirror(Node *root1, Node *root2)
{
    if(!root1 && !root2)
        return true;

    if(root1 && root2 && root1->data==root2->data)
    {
        return isMirror(root1->left, root2->right)
            && isMirror(root1->right, root2->left);
    }

    return false;
}

bool isSymmetric(Node *root)
{
    //for symmetric, it must be mirror image of itself
    return isMirror(root, root);
}

int main()
{
    // Node *root        = newNode(1); 
    // root->left        = newNode(2); 
    // root->right       = newNode(2); 
    // root->left->left  = newNode(3); 
    // root->left->right = newNode(4); 
    // root->right->left  = newNode(4); 
    //root->right->right = newNode(3); 

    Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);

    Node *root2 = newNode(1);
    root2->left = newNode(3);
    root2->right = newNode(2);
    root2->right->right = newNode(4);

    //cout << isSymmetric(root) << endl;
    cout << isMirror(root1, root2) << endl;

    return (0); 
}