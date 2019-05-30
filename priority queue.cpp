#include<iostream>
using namespace std;

class Heap
{
    int *heap;
    int heap_size;
public :
    Heap()
    {
        heap_size = 10;
        heap = new int[heap_size];
        heap[0] = 0;
    }

    void Insert(int x);
    int FindMax();
    int ExtractMax();
    void IncreaseKey(int i,int newKey);
    void DecreaseKey(int i,int newKey);
    void Print();

    int left_child(int parent);
    int right_child(int parent);
    int parent(int child);
    void max_heapify(int root);

    ~Heap()
    {
        heap_size = 0;
        delete []heap;
    }
};

int Heap::left_child(int parent)
{
    return parent*2;
}

int Heap::right_child(int parent)
{
    return parent*2+1;
}

int Heap::parent(int child)
{
    return child/2;
}


void Heap::max_heapify(int root)
{
    int largest,left,right,temp;
    left = left_child(root);
    right = right_child(root);

    if(left<=heap[0] && heap[root]<heap[left])
    {
        largest = left;
    }
    else
        largest = root;

    if(right<=heap[0] && heap[largest]<heap[right])
    {
        largest = right;
    }

    if(largest!=root)
    {
        temp = heap[root];
        heap[root] = heap[largest];
        heap[largest] = temp;
        max_heapify(largest);
    }
}


int Heap::FindMax()
{
    return heap[1];
}

int Heap::ExtractMax()
{
    int high = heap[1];

    heap[1] = heap[heap[0]];
    heap[0] = heap[0] - 1;

    max_heapify(1);

    return high;
}

void Heap::Insert(int x)
{
    int i,t,p;
    heap[0] = heap[0] + 1;
    if(heap[0]>=heap_size)
    {
        int *temp;
        temp = new int[heap_size];
        for(int i=0;i<heap_size;i++)
        {
            temp[i] = heap[i];
        }
        heap = new int[heap_size+10];
        for(int i=0;i<heap_size;i++)
        {
            heap[i] = temp[i];
        }
        heap_size+=10;
    }
    heap[heap[0]] = x;
    i = heap[0];

    while(i>1 && heap[i]>heap[parent(i)])
    {
        p=parent(i);

        t=heap[i];
        heap[i]=heap[p];
        heap[p]=t;

        i=p;

    }
}
void Heap::IncreaseKey(int i,int newKey)
{
    int t,p;
    if(i<=heap[0] && heap[i]<newKey)
    {
        heap[i] = newKey;
        while(i>1 && heap[i]>heap[parent(i)])
        {
            p = parent(i);

            t=heap[i];
            heap[i]=heap[p];
            heap[p]=t;

            i=p;
        }
    }

}

void Heap::DecreaseKey(int i,int newKey)
{
    if(i<=heap[0] && heap[i]>newKey)
    {
        heap[i] = newKey;
        max_heapify(i);
    }
}

void Heap::Print()
{
    for(int j=1;j<=heap[0];j++)
    {
        cout << heap[j] << " ";
    }
    cout << endl;
}

int main()
{
    int ch;
    Heap priorityQueue;
    while(true)
    {
        cout <<
        "1 . Insert Key   2. Find Maximum  3 . Extract Maximum\n" <<
        "4 . Increase Key 5. Decrease Key  6 . Print queue  7 . Quit\n";

        cin >> ch;

        //insert
        if(ch==1)
        {
            int x;
            cin >> x;
            priorityQueue.Insert(x);
        }
        //findMax
        else if(ch==2)
        {
            cout << priorityQueue.FindMax() << endl;
        }
        //extract max
        else if(ch==3)
        {
            cout << priorityQueue.ExtractMax() << endl;
        }
        //increase key
        else if(ch==4)
        {
            int i,newKey;
            cin >> i >> newKey;
            priorityQueue.IncreaseKey(i,newKey);
        }
        //decrease key
        else if(ch==5)
        {
            int i,newKey;
            cin >> i >> newKey;
            priorityQueue.DecreaseKey(i,newKey);
        }
        //print queue
        else if(ch==6)
        {
            priorityQueue.Print();
        }
        //quit
        else if(ch==7)
        {
            break;
        }

    }
}
