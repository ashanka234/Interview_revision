#include<iostream>
#include<cmath>
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
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight, rheight) + 1;
}

bool isBalanced(Node *root)
{
    if(root == NULL)
        return true;        //empty tree is balanced
    
    int lheight = height(root->left);
    int rheight = height(root->right);

    if(abs(lheight-rheight) <= 1
        && isBalanced(root->left)
        && isBalanced(root->right))
            return true;

    return false;
}

int main()
{
    Node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    //root->left->left->left = newNode(8);

    cout << isBalanced(root) << endl;

    return (0);
}