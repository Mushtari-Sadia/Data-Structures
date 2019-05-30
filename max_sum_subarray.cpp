#include<climits>
#include<iostream>
#include<vector>
using namespace std;

vector<int> find_cross_sum(int *A,int low,int mid,int high)
{
    vector<int> x;
    int left_sum = INT_MIN;
    int max_left;
    int sum=0;

    for(int i=mid;i>low;i--)
    {
        sum+=A[i];
        if(sum>left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    int max_right;
    sum=0;

    for(int i=mid+1;i<high;i++)
    {
        sum+=A[i];
        if(sum>right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }

    x.push_back(max_left);
    x.push_back(max_right);
    x.push_back(left_sum+right_sum);

    return x;
}

vector<int> max_sum_subarray(int *A,int low,int high)
{
    vector<int> x,left,right,cross;
    if(high==low)
    {
        x.push_back(low);
        x.push_back(high);
        x.push_back(A[low]);

        return x;
    }
    int mid = (low+high)/2;

    left = max_sum_subarray(A,low,mid);
    right = max_sum_subarray(A,mid+1,high);
    cross = find_cross_sum(A,low,mid,high);

    if(left.at(2)>cross.at(2) && left.at(2)>right.at(2))
    {
        x = left;
    }
    else if(right.at(2)>left.at(2) && right.at(2)>cross.at(2))
    {
        x = right;
    }
    else if(cross.at(2)>left.at(2) && cross.at(2)>right.at(2))
    {
        x = cross;
    }

    return x;
}
int main()
{
    int* a;
    int n;
    cout << "input array size : " << endl;
    cin >> n;
    a = new int[n];

    cout << "input array : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    vector<int> x = max_sum_subarray(a,0,n-1);
    cout << "max sum sub array : start index " << x.at(0)
     << " , end index " << x.at(1) << " , sum " << x.at(2) << endl;

}

