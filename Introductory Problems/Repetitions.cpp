#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>> S;

    int n=S.size();
    int maxi = 0, cnt=1;
    for(int i=0;i<n-1;i++)
    {
        if(S[i]==S[i+1])cnt++;
        else
        {
            maxi = max(maxi , cnt);
            cnt=1;
        } 
    }
    maxi = max(maxi , cnt);
    cout<<maxi<<endl;
    return 0;
}