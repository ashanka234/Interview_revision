#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int d)
{
    Node *temp = new Node;
    temp->data = d;
    temp->next = NULL;

    return temp;
}

void print_list(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void detect_remove_loop(Node *head)
{
    if(head==NULL || head->next==NULL)      //empty list or only 1 node
    {
        return;
    }

    Node *slow = head;
    Node *fast = head;

    slow = slow->next;
    fast = fast->next->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        if(fast == slow)    //loop detected
        {
            break;      //fast will remain at the meeting point
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast == slow)        //agar loop mila hai
    {
        cout << "Loop detected\n";
        slow = head;
        while(fast->next != slow->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        //now dono loop wale node se ek pichle pe hain
        fast->next = NULL;      //breake the loop
    }
}

int main()
{
    Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 

    //loop
    head->next->next->next->next->next = head->next->next;

    detect_remove_loop(head);
    print_list(head);

    return (0);
}