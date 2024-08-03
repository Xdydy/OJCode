#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
string s;
int dp[maxn][2];

map<char,char> wins;
int main () {
    wins['S'] = 'R';
    wins['P'] = 'S';
    wins['R'] = 'P';
    cin >> n ;
    cin >> s;
    s = ' ' + s;
    dp[1][1] = 1;
    dp[1][0] = 0;
    char lastq = s[1];
    char lastw = wins[s[1]];

    for (int i = 2; i <= n; i++) {
        char curw = wins[s[i]];
        char curq = s[i];
        dp[i][1] = dp[i][0] = -n;
        if (curw != lastw) {
            dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
        }
        if (curw != lastq) {
            dp[i][1] = max(dp[i][1], dp[i-1][0] + 1);
        }
        if (curq != lastw) {
            dp[i][0] = max(dp[i][0], dp[i-1][1]);
        }
        if (curq != lastq) {
            dp[i][0] = max(dp[i][0], dp[i-1][0]);
        }
        lastw = curw ;
        lastq = curq;
    }
    cout << max(dp[n][1], dp[n][0]) << endl;
}