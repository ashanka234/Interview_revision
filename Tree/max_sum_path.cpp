#include<iostream>
#include<climits>
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


int max_path_sum(Node *root, int &ans)
{
    if(root == NULL)
        return 0;

    int lsum = max_path_sum(root->left, ans);
    int rsum = max_path_sum(root->right, ans);

    //either left child+node OR right child+node
    //ya fir dono hi nhi include honge
    int max_single = max( max(lsum, rsum) + root->data, root->data);

    //node + max left sum + max right sum
    //ya fir koi ek hoga, upar se jo aaya hai
    int max_top = max(max_single, lsum+rsum+root->data);

    ans = max(ans, max_top);

    return max_top;
}

int main()
{
    Node *root = newNode(10); 
    root->left        = newNode(2); 
    root->right       = newNode(10); 
    root->left->left  = newNode(20); 
    root->left->right = newNode(1); 
    root->right->right = newNode(-25); 
    root->right->right->left   = newNode(3); 
    root->right->right->right  = newNode(4);

    int ans = INT_MIN;
    cout << max_path_sum(root, ans) << endl;

    return (0);
}