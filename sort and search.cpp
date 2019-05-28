#include<iostream>
#include<time.h>
using namespace std;


int linearSearch(int *a,int n,int key){
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
            return i;
    }
    return -1;
}

void bubbleSort(int *a,int n){
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    cout << "sorted array : " << endl;
    for(int i=0;i<n;i++)
    {
        cout << a[i] << endl;
    }
}

void selectionSort(int *a,int n){

    int mini=0;
    for(int i=0;i<n-1;i++)
    {
        mini=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[mini])
            {
                mini=j;
            }
        }
        //a[mini]+=a[0]-(a[0]=a[mini]);
        int temp=a[mini];
        a[mini]=a[i];
        a[i]=temp;

    }
    cout << "sorted array : " << endl;
    for(int i=0;i<n;i++)
    {
        cout << a[i] << endl;
    }

}


int main()
{
    int n,*a,key;
    srand(time(NULL));

    cout << "input size of array : " << endl;
    cin >> n;
    cout << endl;

    a = new int[n];
    int i=0;

    do
    {
        a[i] = rand()%100 + 1;
        cout << a[i] << endl;
        i++;
    }
    while(i<n);

    cout << "\nBy which method do you want the array to be sorted?" << endl;
    cout << "1.bubble sort  2.selection sort  3.insertion sort  4.do not want sorted array" << endl;
    int choice;
    cin>>choice;
    if(choice==1)
        bubbleSort(a,n);
    else if(choice==2)
        selectionSort(a,n);

    cout << "\ninput the key to search : " << endl;
    cin >> key;


    int lin_idx = linearSearch(a,n,key);
    if(lin_idx!=-1)
        cout << key << " was found at " << lin_idx << "-th position by linear search" << endl;
    else
        cout << key << " was not found " << endl;
    delete []a;

}
