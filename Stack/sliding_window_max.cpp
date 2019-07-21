#include<iostream>
#include<deque>
using namespace std;

void print_max_sliding_window(int *arr, int n, int k)
{
    deque<int> qi(k);       //size k ka deque bana h

    //do for first k size window
    int i=0;
    for(i=0; i<k; i++)
    {
        while(!qi.empty() && arr[i]>=arr[qi.back()])        //pichle chote wale hata do
            qi.pop_back();
        
        qi.push_back(i);        //ab yeh max wala hai iss window mei, cuz chote wale nikal diye
    }

    for(i=k; i<n; i++)
    {
        cout << arr[qi.front()] << " ";     //prev window ka answer

        //window ke bahar ka agar reh gya hai max mei, toh remove
        while(!qi.empty() && qi.front()<=i-k)       //greater than i-k wale window ke andar hai, curr pos is i, so window is till i-k
            qi.pop_front();
        
        //now check for new max, by removing all smaller than current
        while(!qi.empty() && arr[i]>=arr[qi.back()])
            qi.pop_back();
        qi.push_back(i);        //add current to back
    }

    //last window ka ans
    cout << arr[qi.front()] << endl;
}

int main()
{
    int t, n, k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        int *arr = new int[n];

        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        print_max_sliding_window(arr,n,k);
    }

    return (0);
}