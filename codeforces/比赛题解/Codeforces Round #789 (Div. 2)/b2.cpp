#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
pair<int, int> ans[maxn];
pair<int,int> dp[maxn][2];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        string s;
        cin >> s;

        
        for ( int i = 0 ; i < n ; i+=2 ) {
            int c1 = 0 ;
            if ( s[i] == '0' ) c1++;
            if ( s[i+1] == '0' ) c1++;
            int c0 = 2-c1;

            if ( i == 0 ) {
                dp[i][0] = {c0, 1};
                dp[i][1] = {c1, 1};
            }
            else {
                dp[i][0] = min(pair<int,int>{dp[i-2][0].first+c0, dp[i-2][0].second}, {dp[i-2][1].first+c0, dp[i-2][1].second+1});
                dp[i][1] = min(pair<int,int>{dp[i-2][0].first+c1, dp[i-2][0].second+1}, {dp[i-2][1].first+c1, dp[i-2][1].second});
            }
        }   

        ans[cas] = min(dp[n-2][0], dp[n-2][1]);
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i].first << " " << ans[i].second << endl;
}