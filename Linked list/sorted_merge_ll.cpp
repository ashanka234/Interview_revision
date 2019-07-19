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

Node *sortedMerge(Node *head1, Node *head2)
{
    Node *res = NULL;

    if(head1 == NULL)   //list 1 finished
    {
        return head2;       //baaki list as it as add ho jayegi
    }

    else if(head2 == NULL)
    {
        return head1;
    }

    //now do actual comparison
    if(head1->data <= head2->data)
    {
        res = head1;    //uss wale node ko ab res bol rhe hain
        //ab res ke next me baaki add kr do recursion se
        res->next = sortedMerge(head1->next, head2);        //head1 aage badhega sirf, head2 wahi rahega
    }
    else
    {
        res = head2;
        res->next = sortedMerge(head1, head2->next);
    }

    return res;
}

int main()
{
    int n1, n2;
    Node *head1, *head2;

    cin >> n1 >> n2;

    while(n1--)
    {
        int n;
        cin >> n;
        push_back(&head1, n);
    }

    while(n2--)
    {
        int n;
        cin >> n;
        push_back(&head2, n);
    }
    //print_list(head1);

    Node *ans = sortedMerge(head1, head2);
    print_list(ans);

    return (0);
}