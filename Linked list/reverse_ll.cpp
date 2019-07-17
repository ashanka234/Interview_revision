#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insert(Node **head, int d)
{
    if(*head == NULL)       //list is empty, so create list
    {
        Node *new_node = new Node;
        new_node->data = d;
        *head = new_node;
        return;
    }

    //insert at end
    Node *new_node = new Node;
    new_node->data = d;

    Node *curr = *head;
    while(curr->next)       //reach last node
    {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->next = NULL;
}

void print(Node *head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reverse(Node **head)
{
    if(*head == NULL)       //empty list
    {
        return;
    }

    Node *first = *head;
    Node *rest = first->next;

    if(rest == NULL)    //only 1 node in ll
    {
        return;
    }

    reverse(&rest);
    first->next->next = first;      //create link from rest to first; isse saare arrow ulte ho jayenge
    first->next = NULL;     //because now first node is the last

    *head = rest;       //rest will be at last node now so that is the new head
}

int main()
{
    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    
    //print(head);

    // reverse(&head);

    // print(head);

    return (0);
}