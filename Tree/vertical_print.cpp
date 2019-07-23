#include<iostream>
#include<map>
#include<vector>
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

// Node *build()
// {
//     int d;
//     cin >> d;

//     if(d == -1)
//         return NULL;

//     Node *root = newNode(d);
//     root->left = build();
//     root->right = build();

//     return root;
// }

Node *buildTree(int in[], Node *root, int i, int n)
{
    if(i<n)
    {
        if(in[i] == -1)
        {
            return NULL;
        }

        Node *temp = newNode(in[i]);
        root = temp;

        root->left = buildTree(in, root->left, 2*i + 1, n);
        root->right = buildTree(in, root->right, 2*i + 2, n);
    }

    return root;
}

void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";        
        inorder(root->right);
    }
}

void generate_vertical_order(Node *root, int hd, map<int, vector<int> > &m)
{
    if(root != NULL)
    {
        m[hd].push_back(root->data);
        generate_vertical_order(root->left, hd-1, m);
        generate_vertical_order(root->right, hd+1, m);
    }
}

void print_vertical_order(Node *root)
{
    int hd=0;
    map< int,vector<int> > m;
    generate_vertical_order(root, hd, m);

    map< int, vector<int> >::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        for(int i=0; i<it->second.size(); i++)
        {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;      //no. of nodes
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter tree in level order:\n";
    Node *root = NULL;
    root = buildTree(arr, root, 0, n);      //enter -1 for NULL 
    //root = build();
    //inorder(root); cout << endl;

    print_vertical_order(root);

    return (0);
}