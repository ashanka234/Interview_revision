#include<iostream>
#include<stack>
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

    if(d==-1)
        return NULL;

    Node *temp = newNode(d);
    root = temp;

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void inorder(Node *root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void zigzag_print(Node *root)
{
    if(!root)
        return;

    stack<Node *> curr_level;
    stack<Node *> next_level;

    bool LtoR = true;       //first level starting from L to R order

    curr_level.push(root);

    while(!curr_level.empty())
    {
        Node *temp = curr_level.top();
        curr_level.pop();

        if(temp != NULL)        //not ended
        {
            cout << temp->data << " ";

            //agar curr wala Left to right hai, toh agla wala right to left hoga
            //toh pehle stack mei left subtree, then right subtree daalo
            //so that pehle right wala nikle agle ke liye
            if(LtoR)
            {
                if(temp->left)
                    next_level.push(temp->left);
                if(temp->right)
                    next_level.push(temp->right);
            }
            else    //curr wala right to left hai, toh agla left ro right hoga
            {
                if(temp->right)
                    next_level.push(temp->right);
                if(temp->left)
                    next_level.push(temp->left);
            }
        }

        if(curr_level.empty())
        {
            LtoR = !LtoR;
            swap(next_level, curr_level);       //next level wala ab curr hoga cuz agle wale usme daale hai
            cout << endl;       //yeh level khatam
        }
    }
}

int main()
{
    // Node *root = NULL;
    // root = buildTree(root);
    // inorder(root); cout << endl;

    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 

    zigzag_print(root); 

    return (0);
}