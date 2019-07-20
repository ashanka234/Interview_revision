#include<iostream>
#include<stack>
using namespace std;

void print_NGE(int *arr, int n)
{
    stack<int> myStack;

    myStack.push(arr[0]);

    for(int i=1; i<n; i++)
    {
        if(myStack.empty())     //khali h toh push kro, and next element se check krna start kro NGE
        {
            myStack.push(arr[i]);
            continue;
        }

        //stack mei harr main element jaa rha hai
        //aur fir arr se usska answer find kr rhe hai
        while(!myStack.empty() && arr[i] > myStack.top())       //jab take arr[i] usse chota nhi hota tab tak check, because wahi wala next greater hoga
        {
            cout << arr[i] << " ";
            myStack.pop();      //jab mil gya ans toh nikal do stack se
        }

        myStack.push(arr[i]);       //agle element ke liye kro
    }

    while(!myStack.empty())
    {
        cout << -1 << " ";
        myStack.pop();
    }
    cout << endl;
}

int main()
{
    int n, t;
    cin >> t;
     
    while(t--)
    {
        cin >> n;
        int *arr = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        print_NGE(arr, n);
    }

     return (0);
}