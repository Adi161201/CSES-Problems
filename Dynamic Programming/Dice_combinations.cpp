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

int func(vector<int> &arr, int i, int tar)
{
    if(tar<0) return 0;
    if(tar==0) return 1;
    
    if(i==0)
    {
        if(tar % arr[0] == 0) return 1;
        return 0;
    }
    int take=0;
    if(arr[i]<=tar) take = func(arr,i, tar-arr[i]);
    int not_take = func(arr,i-1,tar);

    return take + not_take;

}

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
        
        vector<int> arr={1,2,3,4,5,6};
        vector<int> dp;
        dp[0]=1;
        dp[1]=2;

        int sum=0;
        for(int i=0;i<t;i++)
        {   
            if(t<i) break;
            sum+=dp[t-i];
        }
        int ans = func(arr,5,t);
        cout<< ans << endl;

        return 0;
}