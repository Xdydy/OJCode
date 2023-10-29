#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    int dp[205][205];
    int val[205][205];
    int minimumChanges(string s, int k) {
        int n = s.length();
        s = ' ' + s;

        for ( int i = 0 ; i <= n ; i++ ) {
            for ( int j = 0 ; j <= n ; j++ ) {
                dp[i][j] = 1 << 30;
            }
        }
        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = i ; j <= n ; j++ ) {
                if (i == j) {
                    continue;
                }
                int len = j-i+1;
                int cnt = len;
                for ( int d = 1 ; d <= len/2 ; d++ ) {
                    int cnttmp = 0;
                    if (len % d) continue;
                    for ( int u = 1 ; u <= d ; u++ ) {
                        string tmp;
                        for ( int v = i+u-1 ; v <= j ; v += d) {
                            tmp += s[v];
                        }
                        for ( int st = 0 , ed = tmp.size()-1 ; st <= ed ; st++, ed-- ) {
                            if (tmp[st] != tmp[ed] ) {
                                cnttmp++;
                            }
                        }
                    }
                    cnt = min(cnt, cnttmp);
                }
                val[i][j] = cnt;
            }
        }


        for ( int i = 2 ; i <= n ; i++ ) {
            for ( int j = 1 ; j <= min(i/2,k) ; j++ ) {
                if (j == 1) {
                    dp[i][j] = val[1][i];
                    continue;
                }
                for ( int k = i-2 ; k / 2 >= j-1 ; k-- ) {
                    dp[i][j] = min(dp[i][j], dp[k][j-1] + val[k+1][i]);
                }
            }
        }
        
        return dp[n][k];
    }
};