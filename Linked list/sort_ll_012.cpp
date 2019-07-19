#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push_back(Node **head, int d)
{
    Node *newNode = new Node;
    newNode->data = d;
    newNode->next = NULL;
    
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    Node *curr = *head;
    while(curr->next)
        curr = curr->next;
    
    curr->next = newNode;
}

void print_list(Node *head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void sort(Node *head)
{
    if(!head)       //empty list
        return;

    Node *curr = head;
    int count[3] = {0};

    //create frequency array
    while(curr)
    {
        count[curr->data]++;
        curr = curr->next;
    }

    //cout << count[0] << " " << count[1] << " " << count[2] << endl;

    int i=0;
    //i will traverse the count array

    curr = head;
    while(curr)
    {
        if(count[i] == 0)
        {
            i++;        //yeh wale sare laga diye, agla number bharo ab
            continue;
        }

        curr->data = i;     //i is the number 0,1 or 2; array mei uska freq stored hai
        count[i]--;
        curr = curr->next;      //bas data overwrite kr rhe hain
    }
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
            push_back(&head, d);
        }
        //print_list(head);
        sort(head);
        print_list(head);
    }

    return (0);
}