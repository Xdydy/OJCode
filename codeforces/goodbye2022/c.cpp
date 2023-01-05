#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
ll a[105];
ll d[105][105];
bool ans[1005];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n, greater<ll>());
        bool flag = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i + 1]) {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            ans[cas] = 0;
        } else {
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    d[i][j] = a[i] - a[j];
                }
            }
            bool flag = 0;
            int x = 1;
            while (x <= 1000) {
                bool tmp = 1;
                for (int i = 1; i < n; i++) {
                    ll val = a[i] + x;
                    for ( int j = i+1 ; j <= n ; j++ ) {
                        if ( __gcd(val,d[i][j]) != 1 ) {
                            tmp = 0;
                            break;
                        }
                    }
                    if (!tmp) break;
                }
                flag = tmp;
                if(flag) break;
                x++;
            }
            ans[cas] = flag;
        }
    }
    for (int i = 1; i <= T; i++)
        if (ans[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
}