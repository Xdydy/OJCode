#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
string s[2];
int dp[maxn][2];
int ans[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        cin >> s[0];
        cin >> s[1];
        s[0] = ' ' + s[0];
        s[1] = ' ' + s[1];

        int cnt = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( s[0][i] == '*' ) cnt++;
            if ( s[1][i] == '*' ) cnt++;
        }

        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = 0 ; j <= 1 ; j++ ) {
                dp[i][j] = 1 << 30;
            }
        }

        int pos = n;
        for (int i = 1; i <= n; i++) {
            if ( s[0][i] == '.' && s[1][i] == '.' ) continue;
            if (s[0][i] == '*' && s[1][i] == '*') {
                dp[i][0] = dp[i][1] = 1;
                cnt -= 2;
            } else if (s[0][i] == '*') {
                dp[i][0] = 0;
                dp[i][1] = 1;
                cnt--;
            } else if (s[1][i] == '*') {
                dp[i][0] = 1;
                dp[i][1] = 0;
                cnt--;
            } 
            pos = i ;
            break;
        }
        if ( cnt == 0 ) {
            ans[cas] = min(dp[pos][0], dp[pos][1]);
            continue;
        }


        for (int i = pos+1; i <= n; i++) {
            if (s[0][i] == '*' && s[1][i] == '*') {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + 2;
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + 2;
                cnt -= 2;
            } else if (s[0][i] == '*') {
                dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
                dp[i][1] = min(dp[i - 1][1] + 2, dp[i - 1][0] + 2);
                cnt--;
            } else if (s[1][i] == '*') {
                dp[i][0] = min(dp[i - 1][1], dp[i - 1][0]) + 2;
                dp[i][1] = min(dp[i - 1][1] + 1, dp[i - 1][0] + 2);
                cnt--;
            } else {
                dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
                dp[i][1] = min(dp[i - 1][1] + 1, dp[i - 1][0] + 2);
            }
            if ( cnt == 0 ) {
                pos = i ;
                break;
            }
        }
        ans[cas] = min(dp[pos][0], dp[pos][1]);
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i] << endl;
}