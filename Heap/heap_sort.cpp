#include<iostream>
using namespace std;

void heapify(int *arr, int n, int i)        //O(logn)
{
    int curr_largest = i;       //current root
    int left = 2*i + 1;     //left subtree
    int right = 2*i + 2;    //right subtree

    //if left child is larger than root 
    if(left < n && arr[left] > arr[curr_largest])
        curr_largest = left;        //yeh index hai, value nhi
    
    //if right is greater than root & left subtree root
    if(right < n && arr[right] > arr[curr_largest])
        curr_largest = right;

    if(curr_largest != i)       //agar change hua hai
    {
        swap(arr[i], arr[curr_largest]);

        heapify(arr, n, curr_largest);      //recuresively do for all
    }
}

void heap_sort(int *arr, int n)         //O(nlogn)
{
    //build heap
    for(int i= n/2 - 1; i>=0; i--)
    {
        heapify(arr, n, i);
    }

    //extract elements from heap
    for(int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void print_array(int *arr, int n)
{
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(int);

    print_array(arr, n);
    heap_sort(arr, n);
    print_array(arr, n);

    return (0);
}