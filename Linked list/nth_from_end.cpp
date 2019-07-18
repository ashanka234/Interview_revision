#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push_back(Node **head, int d)
{
    Node *new_node = new Node;
    new_node->data = d;
    new_node->next = NULL;

    if(*head == NULL)       //empty list
    {
        *head = new_node;
        return;
    }

    Node *curr = *head;
    while(curr->next)   //reach the last node
    {
        curr = curr->next;
    }
    curr->next = new_node;
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

int nth_from_end(Node *head, int n)
{
    Node *main = head;
    Node *ref = head;

    int cnt = 1;
    while(cnt <=n)
    {
        ref = ref->next;
        cnt++;
    }

    while(ref)        //ref will reach last node
    {
        ref = ref->next;
        main = main->next;      //now main will be at  nth from end, because diff between ref and main is n
    }

    return main->data;
}

int main()
{
    Node *head = NULL;
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);
    push_back(&head, 6);

    print_list(head);

    cout << nth_from_end(head, 3) << endl;      //n=3

    return (0);
}