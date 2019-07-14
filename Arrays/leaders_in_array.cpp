#include<iostream>
using namespace std;

void find_leaders(int *arr, int n)
{
    int max_from_right = arr[n-1];
    int *ans = new int[n];
    int k=0; 

    ans[k++] = max_from_right;

    for(int i=n-2; i>=0; i--)
    {
        if(arr[i] >= max_from_right)
        {
            max_from_right = arr[i];
            ans[k++] = max_from_right;
        }
    }

    int i=k-1;
    while(i>=0)
    {
        cout << ans[i--] << " ";
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

        find_leaders(arr, n);
    }

    return (0);
}