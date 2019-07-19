#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head, int d)
{
    Node *newNode = new Node;
    newNode->data = d;
    newNode->next = NULL;
    
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

bool isPalindrome(Node *head)
{
    stack<int> st;
    Node *curr = head;

    while(curr)
    {
        st.push(curr->data);
        curr = curr->next;
    }

    curr = head;
    while(!st.empty())
    {
        int d = st.top();
        st.pop();

        if(d != curr->data)
        {
            return false;
        }
        curr = curr->next;
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        Node *head = NULL;
        while(n--)
        {
            int d;
            cin >> d;
            push(&head, d);
        }

        cout << isPalindrome(head) << endl;
    }

    return (0);
}