#include<iostream>
#include<climits>
using namespace std;

class Node
{
    public:

    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data  = d;
        left = right = NULL;
    }
};

bool isBST(Node *root, int min, int max)
{
    if(root == NULL)        //reached end
        return true;

    //check for current node
    if(root->data < min || root->data > max)
        return false;

    return isBST(root->left, min, root->data - 1) 
        && isBST(root->right, root->data + 1, max);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << isBST(root, INT_MIN, INT_MAX) << endl;

    return (0);
}