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

Node *buildTree(Node *root)
{
    int d;
    cin >> d;

    if(d != -1)
    {
        root = newNode(d);
        root->left = buildTree(root->left);
        root->right = buildTree(root->right);
    }

    return root;
}

void print_inorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

void leftView(Node *root, int level, int *max_level)
{
    if(root == NULL)
        return;

    //if it is first level
    if(level > *max_level)
    {
        cout << root->data << " ";
        *max_level = level;
    }

    leftView(root->left, level+1, max_level);
    leftView(root->right, level+1, max_level);
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        Node *root = newNode(12);
        root->left = newNode(10);
        root->right = newNode(30);
        root->right->left = newNode(25); 
        root->right->right = newNode(40); 

        int max_lvl = 0;
        leftView(root, 1, &max_lvl);
        //print_inorder(root); cout << endl;
        // Node *root = NULL;
        // root = buildTree(root);
        // print_inorder(root);
    }

    return (0);
}