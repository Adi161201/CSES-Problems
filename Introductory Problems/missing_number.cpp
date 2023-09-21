#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        arr[i]=x;
    }
    int curr_sum=0;
    int total_sum = ( (long)(n)* (long)(n+1)) /2;
    for(auto x:arr) curr_sum+=x;

    cout<< total_sum - curr_sum<<endl;
    return 0;

}