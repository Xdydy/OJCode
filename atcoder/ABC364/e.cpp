#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int x,y;
int a[maxn],b[maxn];
int dp[100][10005];
int dp2[100][10005];

int main () {
    IOS;
    cin >> n >> x >> y;
    for ( int i = 1 ; i <= n ; i++ )  {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= 10000; j++) {
            dp[i][j] = 10001;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n ; i++) {
        for (int j = x; j-a[i] >= 0; j--) {
            for (int k = 1; k <= n; k++) {
                dp[k][j] = min(dp[k][j], dp[k-1][j-a[i]] + b[i]);
            }
        }
    }
    int maxx = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (dp[i][j] <= y) {
                maxx = max(maxx, i);
            }
        }
    }
    cout << min(maxx+1,n) << endl;
}