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

void rotate_by_k(Node **head, int k)
{
    if(k==0)
    {
        return;
    }

    Node *curr = *head;
    int cnt=0;

    //reach the kth node, iske baad se list start hogi
    while(cnt<=k && curr!=NULL)
    {
        cnt++;
        curr = curr->next;
    }

    if(curr == NULL)        //matlab k >=l ength of list, toh same hi rahega
    {
        return;
    }

    Node *kth_node = curr;

    //now reach till end
    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    //link last node to head
    curr->next = *head;

    //list start from k+1th node
    *head = kth_node->next;

    //terminate list at kth node
    kth_node->next = NULL;
}

int main()
{
    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    print(head);

    rotate_by_k(&head, 3);      //for k=3

    print(head);

    return (0);
}