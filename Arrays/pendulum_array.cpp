#include<iostream>
#include<algorithm>
using namespace std;

void make_pendulum(int *arr, int n)
{
    sort(arr, arr+n);

    int *ans = new int[n];

    int mid = (n-1)/2;

    ans[mid] = arr[0];
    int i=1, j=1;   //j for traversing arr, i for ans

    for(int i=1; i<=mid; i++)
    {
        ans[mid+i] = arr[j++];  //next greter to right
        ans[mid-i] = arr[j++];  //next to next to left
    }

    //for even no of lements
    if(n%2 == 0)
    {
        ans[mid+i] = arr[j];
    }
    
    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
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

        make_pendulum(arr, n);
    }   

    return (0);
}