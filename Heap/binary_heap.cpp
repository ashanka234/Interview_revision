#include<iostream>
using namespace std;

class minHeap
{
    int *heap_arr;
    int capacity;
    int heap_size;

public:
    minHeap(int cap)        //constructor
    {
        capacity = cap;
        heap_size = 0;
        heap_arr = new int[cap];
    }

    int parent(int i)
    {
        return (i-1)/2;
    }

    int left(int i)
    {
        return 2*i + 1;
    }

    int right(int i)
    {
        return 2*i + 2;
    }

    void insert_key(int k)
    {
        if(heap_size == capacity)       //overflow
        {
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        heap_arr[i] = k;

        //child should be greater than parent since it is a min heap
        //parent() will return current waale ka parent index jo 2i + 1 se aata hai
        while(i > 0 && heap_arr[parent(i)] > heap_arr[i])
        {
            swap(heap_arr[parent(i)], heap_arr[i]);
            i = parent(i);
        }
    }

    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if(l<heap_size && heap_arr[l] < heap_arr[i])
            smallest = i;
        if(r<heap_size && heap_arr[r] < heap_arr[i])
            smallest = r;

        if(smallest != i)
        {
            swap(heap_arr[i], heap_arr[smallest]);
            heapify(smallest);
        }
    }
};

int main()
{

}