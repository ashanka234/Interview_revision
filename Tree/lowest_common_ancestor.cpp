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

Node *buildTree(int *arr, int i,  int n, Node *root)
{
    if(i < n)
    {
        if(arr[i] == -1)
            return NULL;

        Node *temp = newNode(arr[i]);

        root = temp;
        root->left = buildTree(arr, 2*i + 1, n, root->left);
        root->right = buildTree(arr, 2*i + 2, n, root->right);
    }

    return root;
}

void inorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *find_LCA(Node *root, int n1, int n2)
{
    if(!root)
        return NULL;

    //if one is ancestor of other
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }

    Node *left_LCA = find_LCA(root->left, n1, n2);
    Node *right_LCA = find_LCA(root->right, n1, n2);

    //agar yeh dono kuch ans return kr rhe hain
    //means ki current ki ek subtree mei n1 hai dusri mei n2
    //matlab curr wala hi LCA hai
    if(left_LCA && right_LCA)
        return root;

    if(left_LCA)
        return left_LCA;
    else
    {
        return right_LCA;
    }
    
}

int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    root = buildTree(arr, 0, n, root);
    //inorder(root); cout << endl;
    Node *lca = find_LCA(root, 4, 3);
    cout << lca->data << endl;

    return (0);
}