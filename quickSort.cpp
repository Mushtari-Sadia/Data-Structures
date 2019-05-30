#include<iostream>
using namespace std;


int Partition(int *arr,int low,int high)
{
    int i = low - 1;
    int pivot = high;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=arr[pivot])
        {
            i++;

            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    int t = arr[i+1];
    arr[i+1] = arr[pivot];
    arr[pivot] = t;

    return pivot;
}

void quicksort(int *arr,int low,int high)
{
    if(low>=high)
    {
        return;
    }

    int p = Partition(arr,low,high);
    quicksort(arr,low,p-1);
    quicksort(arr,p+1,high);
}

int main()
{
    while(true){
    int *arr,sz;
    cout << "input size and array to sort : " << endl;
    cin >> sz;
    arr = new int[sz];
    for(int i=0;i<sz;i++)
    {
        cin >> arr[i];
    }
    quicksort(arr,0,sz-1);

    cout << "\nAfter sorting :\n";
    for(int i=0;i<sz;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    delete []arr;
    }

}
