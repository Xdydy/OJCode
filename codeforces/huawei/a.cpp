#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int dp[50][10];
int m , n, k ;

int main () {
    cin >> m >> n >> k ;
    set<int> st;
    for ( int i = 1 ; i <= k ; i++ ) {
        int x ; cin >> x;
        st.insert(x);
    }

    dp[0][m] = 1;
    for ( int i = 1 ; i <= n+1 ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( st.find(i) == st.end() ) {
                dp[i][j] = dp[i-1][j];
                if ( i >= 2 ) {
                    dp[i][j] += dp[i-2][j];
                }
                if ( i >= 3 ) {
                    dp[i][j] += dp[i-3][j];
                }
            } else {
                dp[i][j] = dp[i-1][j+1];
                if ( i >= 2 ) {
                    dp[i][j] += dp[i-2][j+1];
                }
                if ( i >= 3 ) {
                    dp[i][j] += dp[i-3][j+1];
                }
            }
        }
    }

    int ans = 0 ;
    for ( int i = 1 ; i <= m ; i++ ) {
        ans += dp[n+1][i];
    }
    cout << ans << endl;
}