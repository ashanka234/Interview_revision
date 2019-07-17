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

void reverse_groups_of_k(Node **head, int k)
{
     Node *curr = *head;
     Node *next = NULL;
     Node *prev = NULL;
     int i=0;

     //reverse first k group
     while(i<k && curr!=NULL)
     {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
         i++;       //this will happen k times
     }

     //no recursion will do for rest 
     if(next != NULL)       //not reached end
     {
         reverse_groups_of_k(&next, k);
     }

     *head = prev;     //prev will be the new head since it is at end now
}

int main()
{
    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);
    insert(&head, 8);
    insert(&head, 9);

    print(head);

    reverse_groups_of_k(&head, 3);      //for k=3

    print(head);

    return (0);
}