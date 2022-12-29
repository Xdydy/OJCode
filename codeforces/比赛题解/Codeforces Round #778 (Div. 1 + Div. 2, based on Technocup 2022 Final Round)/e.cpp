#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int n ;
int a[maxn];
int S = 70;

int b[100005*70];
unordered_map<int,int> dp[maxn];

int solve() 
{
    int res = 0 ;
    for ( int d = 0 ; d < S ; d++ )
    {
        for ( int i = 1 ; i <= n ; i++ )
            res = max(res, ++b[a[i]+(n-i)*d]);
        for ( int i = 1 ; i <= n ; i++ )
            b[a[i]+(n-i)*d] = 0;
    }

    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = max(1, i-100005/S) ; j < i ; j++ )
        {
            int d = (a[i]-a[j]) / (i-j);
            int r = (a[i]-a[j]) % (i-j);
            if ( r == 0 && d >= S )
            {
                dp[i][d] = max(dp[i][d], dp[j][d]+1);
                res = max(res, dp[i][d]+1);
            }
        }
    }
    for ( int i = 1 ; i <= n ; i++ )
        dp[i].clear();

    return res;
}

int main ()
{
    IOS;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    int ans = solve();
    reverse(a+1, a+1+n);
    ans = max(ans, solve());
    cout << n-ans << endl;
}
