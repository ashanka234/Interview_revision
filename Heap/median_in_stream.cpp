#include<iostream>
#include<queue>
using namespace std;

void print_medians(int *arr, int n)
{
    priority_queue<int> s;      //max heap for smaller elements (left)
    priority_queue<int, vector<int>, greater<int> > g;      //min heap for greater elements (right)

    s.push(arr[0]);
    float median = arr[0];

    cout << median << " ";

    for(int i=1; i<n; i++)
    {
        int x = arr[i];

        //if left heap has more elements
        if(s.size() > g.size())
        {
            if(x < median) 
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
            {
                g.push(x);
            }
            median = (s.top() + g.top()) / 2.0;
        }
        
        //both are balanced size
        else if (g.size() == s.size())
        {
            if(x < median)
            {
                s.push(x);
                median = (float)s.top();
            }
            else
            {
                g.push(x);
                median = (float)g.top();
            }
        }

        //right heap is bigger
        else
        {
            if(x > median)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
            {
                s.push(x);
            }
            median = (s.top() + g.top()) / 2.0;
        }

        cout << median << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 10, 15, 30};
    int n = sizeof(arr)/sizeof(int);

    print_medians(arr, n);

    return (0);
}

