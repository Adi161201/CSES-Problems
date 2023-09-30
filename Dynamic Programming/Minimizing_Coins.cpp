#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// int func(vector<int> &arr, int i, int tar, vector<vector<int>> &dp)
// {
//     if(tar<0) return 1e7;
//     if(tar==0) return 0;
//     if(i==0)
//     {
//         if(tar%arr[0]==0) return tar/arr[0];
//         return 1e7;
//     }
//     if(dp[i][tar]!=-1) return dp[i][tar];

//     int take=1e7 , not_take =1e7;

//     if(arr[i]<=tar) take = 1 + func(arr,i,tar-arr[i],dp);
//     not_take = func(arr,i-1,tar,dp);
//     // cout<<take<<" "<<not_take<<endl;
//     return dp[i][tar] = min(take,not_take);
// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int n=t;

    int tar;
    cin>>tar;
    vector<int> arr;
    while (t--)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    
    vector<vector<int>> dp(n, vector<int>(tar+1,1e7));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= tar; ++j) {
        if (j % arr[0] == 0) {
            dp[0][j] = j / arr[0];
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= tar; ++j) {
            if (j >= arr[i]) {
                int take = 1 + dp[i][j - arr[i]];
                int not_take = dp[i - 1][j];
                dp[i][j] = min(take, not_take);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ans = dp[n-1][tar];
    if(ans>=1e7) ans=-1;
    cout<<ans<<endl;
    return 0;
}