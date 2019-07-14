#include<iostream>
using namespace std;

void subarray_sum(int *arr, int n, int sum)
{
    int curr_sum=arr[0];
    int j=0;

    for(int i=1; i<=n; i++)
    {
        //curr exceeds target, subtract starting element
        while(curr_sum > sum && j <i-1)
        {
            curr_sum -= arr[j];
            j++;
        }

        //curr equals target, return
        if(curr_sum == sum)
        {
            cout << j+1 << " " << i << endl;
            return;
        }

        if(i<n)
        {
            curr_sum += arr[i];
        }
    }
    cout << -1 << endl;     //no solution
}

int main()
{
    int t, n, sum;
    cin >> t;

    while(t--)
    {
        cin >> n >> sum;
        int *arr = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        subarray_sum(arr,n,sum);
    }

    return (0);
}