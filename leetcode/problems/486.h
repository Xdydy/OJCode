#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    int dp[25][25];
    bool predictTheWinner(vector<int>& a) {
        int n = a.size();
        memset(dp,0,sizeof(dp));
        for ( int i = 1; i <= n ; i++ ) dp[i][i] = a[i-1];
        for ( int len = 2 ; len <= n ; len++ ) {
            for ( int st = 1 ; st + len - 1 <= n ; st++ ) {
                int ed = st+len-1;
                dp[st][ed] = max(a[st-1] - dp[st+1][ed], a[ed-1] - dp[st][ed-1]);
            }
        }
        return dp[1][n] >= 0;
    }
};