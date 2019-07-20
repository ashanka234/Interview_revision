#include<iostream>
#include<stack>
using namespace std;

class specialStack
{
    stack<int> s;
    int min_element;

public:
    void push(int d)
    {
        if(s.empty())
        {
            s.push(d);
            min_element = d;
            return;
        }

        if(d < min_element)     //new min found
        {
            s.push(2*d - 1);
            min_element = d;
        }

        else
        {
            s.push(d);
        }
    }

    int pop()
    {
        if(s.empty())
        {
            return 0;
        }

        int x = s.top();
        s.pop();
        //cout << x << " ";       //top most element popped

        if(x < min_element)     //matlab yeh wala min tha, toh ab naya banega min
        {
            min_element = 2*min_element - x;
        }

        return x;
    }

    int getMin()
    {
        return min_element;
    }
};

int main()
{
    int t;
    cin >> t;

    specialStack myStack;

    while(t--)
    {
        int n;      //no. of queries
        cin >> n;

        while(n--)
        {
            int q;
            cin >> q;
            if(q == 1)
            {
                int d;
                cin >> d;
                myStack.push(d);
                //n--;
            }
            else if(q == 2)
            {
                cout << myStack.pop() << " ";
            }
            else    //q==3
            {
                cout << myStack.getMin() << " ";
            }
            cout << endl;
        }
    }

    return (0);
}