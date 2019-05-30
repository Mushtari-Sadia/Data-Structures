#include<iostream>
using namespace std;

class min_heap
{
    int *heap;
    int heap_size;

    int parent(int child)
    {
        return child/2;
    }
    int left_child(int parent)
    {
        return parent*2;
    }
    int right_child(int parent)
    {
        return parent*2+1;
    }

    void min_heapify(int heap[],int heap_size,int root)
    {
        //cout << "min heapify" << endl;
        if(root>=heap_size)
        {
            return;
        }


        int smallest,temp,left,right;
        left = left_child(root);
        right = right_child(root);


        if(left<=heap_size && heap[left]<heap[root])
        {
            smallest = left;
        }
        else
            smallest = root;

        if(right<=heap_size && heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if(smallest!=root)
        {
            temp = heap[root];
            heap[root] = heap[smallest];
            heap[smallest] = temp;
            min_heapify(heap,heap_size,smallest);
        }


    }
public:
    min_heap()
    {
        heap_size = 0;
        heap = new int[heap_size];
    }
    min_heap(int heap[],int heap_size)
    {
        //cout << "constructing" << endl;
        this->heap_size = heap_size;
        this->heap = heap;

        for(int i=heap_size/2;i>=1;i--)
        {
            min_heapify(heap,heap_size,i);
        }
    }

    void printHeap()
    {
        for(int i=1;i<=heap_size;i++)
        {
            cout << heap[i] << endl;
        }
    }
};

int main()
{
    int heap_size;
    cout << "input heap size : " << endl;
    cin >> heap_size;

    int heap[heap_size];
    cout << "input heap elements : " << endl;
    for(int i=1;i<=heap_size;i++)
    {
        cin >> heap[i];
    }

    min_heap mh(heap,heap_size);
    mh.printHeap();
}
