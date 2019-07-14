#include<iostream>
using namespace std;

void print_smaller(int *arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        if(arr[i+1] < arr[i])
        {
            cout << arr[i+1] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
    cout << -1 << endl;
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int *arr = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        print_smaller(arr, n);
    }

    return (0);
}