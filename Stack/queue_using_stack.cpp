#include<iostream>
#include<stack>
using namespace std;

class Queue
{
    stack<int> s1;      //main
    stack<int> s2;      //aux

public:

    void push(int d)
    {
        if(s1.empty())
        {
            s1.push(d);
            return;
        }

        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(d);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int t = s1.top();
        s1.pop();

        return t;
    }
};

int main()
{
    int t, q, x, d;

    cin >> t;
    while(t--)
    {
        Queue myQueue;
        cin >> q;       //no. of queries

        while(q--)
        {
            cin >> x;
            if(x == 1)      //push
            {
                cin >> d;
                myQueue.push(d);
            }
            else        //pop
            {
                cout << myQueue.pop() << endl;
            }
            
        }
        cout << endl;
    }

    return (0);
}