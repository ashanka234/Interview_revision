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

bool isIdentical(Node *root1, Node *root2)
{
    if(!root1 && !root2)        //both are empty
        return true;

    return (root1->data == root2->data)
        && (isIdentical(root1->left, root2->left))
        && (isIdentical(root1->right, root2->right));

    //one is empty, other is not
    return false;
}

int main()
{
    Node *a = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);

    Node *b = newNode(4);
    b->left = newNode(2);
    b->right = newNode(3);

    cout << isIdentical(a, b) << endl;

    return (0);
}