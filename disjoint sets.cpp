#include<iostream>
#include<climits>
using namespace std;


class disjoint_set
{
    int id;
    int *parent;
    int *rank;
    int maxSize;
    public:

        disjoint_set(int maxSize)
        {
            this->maxSize = maxSize;
            parent = new int[maxSize+1];
            rank = new int[maxSize+1];
            for(int i=0;i<maxSize+1;i++)
            {
                parent[i] = INT_MIN;
                rank[i] = INT_MIN;
            }
        }


        void make_set(int x);
        int find_set(int x);
        void Union(int x,int y);
        void print(int x);
        void Link(int x,int y);
};

void disjoint_set::make_set(int x)
{
    parent[x] = x;
    rank[x] = 0;

}

int disjoint_set::find_set(int x)
{
    if(parent[x]!=INT_MIN){
        if(x!=parent[x])
        {
            parent[x] = find_set(parent[x]);
        }
    }
    return parent[x];
}

void disjoint_set::Link(int x,int y)
{
     if(rank[x]!=INT_MIN && rank[y]!=INT_MIN){
        if(rank[x]>rank[y])
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
            if(rank[x]==rank[y])
            {
                rank[y] = rank[y]+1;
            }
        }
    }

}

void disjoint_set::Union(int x,int y)
{
    Link(find_set(x),find_set(y));
}

void disjoint_set::print(int x)
{
    int rep = find_set(x);
    cout << "printing set : " << endl;
    for(int i=0;i<maxSize+1;i++)
    {
        if(find_set(parent[i])==rep)
        {
            if(parent[i]!=INT_MIN)
                cout << parent[i] << " ";
        }
    }
    cout << endl;
}


int main()
{
    int n,ch;
    cout << "input the maximum possible element in a set : " << endl;
    cin >> n;
    disjoint_set ds(n);
    do
    {
        cout << "1. Make Set  2. Find Set  3. Union  4. Print Set  5. Exit" << endl;
        cin >> ch;
        if(ch==1)
        {
            int x;
            cout << "input element (less than or equal to " << n << " ) :" << endl;
            cin >> x;
            if(x>n)
            {
                cout << "please input element (LESS THAN OR EQUAL TO " << n << " ) :" << endl;
                cin >> x;
            }

            ds.make_set(x);
        }
        else if(ch==2)
        {
            int x;
            cout << "input element (less than or equal to " << n << " ) :" << endl;
            cin >> x;
            while(x>n)
            {
                cout << "please input element (LESS THAN OR EQUAL TO " << n << " ) :" << endl;
                cin >> x;
            }
            if(ds.find_set(x)!=INT_MIN)
                cout << "Required set representative : " << ds.find_set(x) << endl;
            else
                cout << "***element does not belong to any set***" << endl;
        }
        else if(ch==3)
        {
            int x,y;
            cout << "input two elements of two sets (less than or equal to " << n << " ) :" << endl;
            cin >> x >> y;
            while(x>n || y>n)
            {
                cout << "please input two elements of two sets (LESS THAN OR EQUAL TO " << n << " ) :" << endl;
                cin >> x >> y;
            }

            ds.Union(x,y);
        }
        else if(ch==4)
        {
            int x;
            cout << "input set element (less than or equal to " << n << " ) :" << endl;
            cin >> x;
            while(x>n)
            {
                cout << "please input element (LESS THAN OR EQUAL TO " << n << " ) :" << endl;
                cin >> x;
            }

            ds.print(x);
        }
    }
    while(ch!=5);
}
