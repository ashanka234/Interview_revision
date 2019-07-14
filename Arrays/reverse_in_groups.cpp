#include<iostream>
using namespace std;

void reverse_k(int *arr, int n, int k)
{
    int left, right;

    for(int i=0; i<n; i+=k)
    {
        left = i;
        right = i+k-1;

        if(n-1-i < k)       //last group if n is not multiple of k
        {
            right = n-1;
        }
        while(left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    int n,k,t;

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int *arr = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        reverse_k(arr, n, k);

        for(int i=0; i<n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return (0);
}