#include<iostream>
#include<queue>
using namespace std;

void print_kth_largest(int k)
{
    int num, cnt=0;
    int *arr = new int[k];      //we will store only max k elements
    priority_queue< int, vector<int>, greater<int> > minHeap;

    while(1)
    {
        cout << "Enter num: ";
        cin >> num;
        //cout << cnt << " ";

        //for first k-1 elements, do nothing
        //cout << 1 << " ";
        if(cnt < k-1)
        {
            //cout << 1 << " ";
            arr[cnt]  = num;
            //cout << cnt << " ";
            cnt++;
        }

        else
        {
            if(cnt == k-1)      //it is kth element
            {
                arr[k-1] = num;
                minHeap.push(num);
            }

            else
            {
                if(num > minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(num);
                }
            }
        }
        cout << minHeap.top() << endl;
        cnt++;
    }
}

int kth_max(int *arr, int n, int k)
{
    priority_queue<int> maxHeap;

    for(int i=k; i<n; i++)
    {
        if(i < k-1)
        {
            maxHeap.push(arr[i]);
        }
        else
        {
            if(arr[i] < maxHeap.top())
            {
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
    }
    return maxHeap.top();
}

int main()
{
    int k, n;
    cin >> n >> k;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << kth_max(arr, n, k) << endl;

    return (0);
}