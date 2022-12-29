#include<bits/stdc++.h>
using namespace std;
#define max_size (int)(1e3+10)

int n;
int a[max_size] , sum[max_size];
int dp[max_size][max_size];
int main ()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    for ( int i = 1 ; i <= n ; i++ ) sum[i] = sum[i-1] + a[i];
    for ( int len = 1 ; len <= n ; len++ )
        for ( int i = 1 ; i <= 2 * n - 1 ; i++ )
        {
            int j = len + i - 1;
            for ( int k = i ; k < j && k <= 2*n-1 ; k++ )
                dp[i][j] = max ( dp[i][j] , dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1] );
        }
    cout << dp[1][n] << endl;
}