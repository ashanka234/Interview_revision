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
    if (!root)
    {
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight,rheight) + 1;
}

int diameter(Node *root)
{
    if(!root)
        return 0;

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int diameter_optimised(Node *root, int *height)         //O(n) solution
{
    int lheight = 0, rheight = 0;
    int ldiameter = 0, rdiameter = 0;

    if(!root)
    {
        *height = 0;
        return 0;       //diamter will also be zero if height is 0
    }

    ldiameter = diameter_optimised(root->left, &lheight);
    rdiameter = diameter_optimised(root->right, &rheight);

    *height = max(lheight, rheight) + 1;

    return max(lheight+rheight+1, max(ldiameter, rdiameter));

}

int main()
{
    Node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 

    cout << diameter(root) << endl;
    int height = 0;
    cout << diameter_optimised(root, &height) << endl;

    return (0);
}