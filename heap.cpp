#include<iostream>
using namespace std;

int left_child(int parent)
{
    return parent*2;
}

int right_child(int parent)
{
    return parent*2+1;
}

int parent(int child)
{
    return child/2;
}


void max_heapify(int heap[],int heap_size,int root)
{
    int largest,left,right,temp;
    left = left_child(root);
    right = right_child(root);

    if(left<=heap_size && heap[root]<heap[left])
    {
        largest=left;
    }
    else
        largest = root;

    if(right<=heap_size && heap[largest]<heap[right])
    {
        largest = right;
    }

    if(largest!=root)
    {
        temp = heap[root];
        heap[root] = heap[largest];
        heap[largest] = temp;
        max_heapify(heap,heap_size,largest);
    }
}

void build_max_heap(int heap[],int heap_size)
{
    //i=heap_size/2 because we want to apply the funtion to the last
    //root of the tree,so heap_size(index of last child)/2=index of last parent
    for(int i=heap_size/2;i>=1;i--)
    {
        max_heapify(heap,heap_size,i);
    }
}


void heap_sort(int heap[],int heap_size)
{
    int i,t;

    for(i=heap_size;i>1;i--)
    {
        t=heap[i];
        heap[i]=heap[1];
        heap[1]=t;

        heap_size-=1;
        max_heapify(heap,heap_size,1);
    }
}

int findMinElement(int heap[],int heap_size)
{
    int min = heap[heap_size/2 + 1];
    for(int i=heap_size/2 + 1;i<heap_size;i++)
    {
        if(heap[i]<min)
        {
            min = heap[i];
        }
    }
    return min;
}

int main()
{
    int heap_size,*heap,i=1;
    cout << "input heap size : " << endl;
    cin >> heap_size;

    heap = new int[heap_size];
    cout << "input heap elements : " << endl;
    do{
        cin >> heap[i];
        i++;
    }
    while(i<=heap_size);

    /*cout << "\nHeap : " << endl;
    for(int j=1;j<=heap_size;j++)
    {
        cout << heap[j] << endl;
    }*/

    build_max_heap(heap,heap_size);
    cout << "\nAfter heapifying : " << endl;

    for(int j=1;j<=heap_size;j++)
    {
        cout << heap[j] << endl;
    }


    /*heap_sort(heap,heap_size);
    cout << "\nAfter sorting : " << endl;\

    for(int j=1;j<=heap_size;j++)
    {
        cout << heap[j] << endl;
    }*/

    cout << "minimum element : " << findMinElement(heap,heap_size) << endl;

    delete []heap;
}
