#include<iostream>
#include<cmath>
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

void print_list(Node *head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//this function converts ll into number
int get_num(Node *head)
{
    int num=0;
    int exp=0;

    while(head)
    {
        num += (head->data) * pow(10, exp);
        exp++;
        head=head->next;
    }

    return num;
}

void print_list_reverse(Node *head)
{
    if(head == NULL)
    {
        return;
    }

    print_list_reverse(head->next);
    cout << head->data << " ";
}

void ll_sum(Node *head1, Node *head2)
{
    int n1 = get_num(head1);
    int n2 = get_num(head2);
    int sum = n1 + n2;

    Node *ans = NULL;

    while(sum)
    {
        int digit = sum%10;
        push(&ans, digit);
        sum = sum/10;
    }

    print_list_reverse(ans);
    cout << endl;
}

int main()
{
    // Node *head = NULL;
    // push(&head, 4);
    // push(&head, 5);
    // print_list(head);

    int t;
    cin >> t;

    while(t--)
    {
        int l1, l2, n;
        Node *head1 = NULL; //first num
        Node *head2 = NULL; //second num

        //input first num
        cin >> l1;
        while(l1--)
        {
            cin >> n;
            push(&head1, n);
        }
        //print_list(head1);

        //input second num
        cin >> l2;
        while(l2--)
        {
            cin >> n;
            push(&head2, n);
        }
        //print_list(head2);

        //cout << ll_sum(head1, head2) << endl;
        //cout << get_num(head1) << " " << get_num(head2) << endl;
        ll_sum(head1, head2);
    }

    return (0);
}