#include<iostream>
#include<queue>
#include<map>
#include<climits>
using namespace std;

class Node 
{
public:
    int data;
    int hd;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
        hd = INT_MAX;
    }
};

void print_bottom_view(Node *root)
{
    if(!root)
        return;

    int hd=0;       //horizontal distance
    map<int, int> m;        //key is hd, val is the node value
    queue<Node *> q;

    //hd of root is 0
    root->hd = hd;      //for curr level
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        hd = temp->hd;

        m[hd] = temp->data;

        if(temp->left != NULL)      //leaf not reached
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }

        if(temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }

    map<int,int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        cout << it->second << " ";
    }

    cout << endl;
}

int main()
{
    Node *root = new Node(12);
    root->left = new Node(10);
    root->right = new Node(30);
    root->right->left = new Node(25);
    root->right->right = new Node(40);

    print_bottom_view(root);

    return (0);
}