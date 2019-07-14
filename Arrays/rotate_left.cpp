#include<iostream>
using namespace std;

void rotate_left(int *arr, int n)       //rotate left by one 
{
    int temp=arr[0];
    int i;
    
    for(i=0; i<n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[i] = temp;
}

void rotate_array(int *arr, int n, int d)
{
    for(int i=1; i<=d; i++)
    {
        rotate_left(arr, n);
    }
}

int main()
{
    int t, n, d;
    cin >> t;

    while(t--)
    {
        cin >> n;
        int *arr = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        cin >> d;

        rotate_array(arr, n, d);

        for(int i=0; i<n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return (0);
}