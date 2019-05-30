#include<iostream>
#include<climits>
using namespace std;


void find_combination(int *a2,int *d,int f_idx,int l_idx,int idx,int r,int time[][2],int maxCount,int *a);

void printSolution(int a[],int n,int r,int time[][2])
{
    int d[r];
    int a2[n];
    for(int i=0;i<n;i++)
    {
        a2[i]=i;
    }
    find_combination(a2,d,0,n-1,0,r,time,r,a);
}
void find_combination(int *a2,int *d,int f_idx, int l_idx,int idx, int r,int time[][2],int maxCount,int *a)
{
    if(idx==r)
    {
        int count=0;
        int prev = d[0];
        count++;
        for(int j=1;j<r;j++)
        {
            if(time[prev][1]<=time[d[j]][0])
            {

                count++;
                prev = d[j];
            }

        }

        if(count==maxCount)
        {
            for(int j=0;j<r;j++)
            {
               cout << a[d[j]] << " ";
            }
            cout << endl;
        }

        return;
    }
    for(int i=f_idx;i<=l_idx && l_idx-i+1 >= r-idx;i++)
    {
        d[idx] = a2[i];
        find_combination(a2,d,i+1,l_idx,idx+1,r,time,maxCount,a);
    }
}



int main()
{
    int activity;
    cout << "input number of activities : " << endl;
    cin >> activity;
    int time[activity][2];
    int a[activity];

    cout << "input start time and end time : " << endl;
    for(int i=0;i<activity;i++)
    {
        cout << "activity " << i+1 << " : ";
        cin >> time[i][0] >> time[i][1];
        a[i] = i+1;
        cout << endl;
    }


    //sorting
    for(int i=0;i<activity-1;i++)
    {
        int min = i;
        for(int j=i+1;j<activity;j++)
        {
            if(time[j][1]<time[min][1])
            {
                min = j;
            }
        }
        int temp0 = a[min];
        int temp1 = time[min][1];
        int temp2 = time[min][0];

        a[min] = a[i];
        time[min][1] = time[i][1];
        time[min][0] = time[i][0];

        a[i] = temp0;
        time[i][1] = temp1;
        time[i][0] = temp2;


    }

    int count;
    int maxCount = 0;
    //using greedy method to find atleast one optimal solution
    for(int i=0;i<activity;i++){
        count = 0;
        int prev = i;
        count++;
        for(int j=i+1;j<activity;j++)
        {
            if(time[prev][1]<=time[j][0])
            {
                prev = j;
                count++;
            }
        }
        if(count>maxCount)
        {
            maxCount = count;
        }
    }

    cout << "All possible maximum-size subset of mutually compatible activities (activities are 1 indexed) : " << endl;
    printSolution(a,activity,maxCount,time);
}

