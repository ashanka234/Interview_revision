#include<iostream>
#include<algorithm>
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

int height(Node *root)
{
    if(!root)
        return 0;       //height of root is 0

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight, rheight) + 1;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);

    cout << height(root) << endl;

    return (0);
    
}