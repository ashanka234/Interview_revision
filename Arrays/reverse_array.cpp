#include<iostream>
using namespace std;

void reverse_array(int *arr, int s, int e)
{
    if(s >= e)
    {
        return;
    }

    int temp = arr[s];
    arr[s] = arr[e];
    arr[e] = temp;

    reverse_array(arr, s+1, e-1);
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

        reverse_array(arr, 0, n-1);

        for(int i=0; i<n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return (0);
}