#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
int ans[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        if (a[1] == 0) {
            int pos = n+1;
            for (int i = 2; i <= n; i++) {
                if (a[i] != 0) {
                    pos = i;
                    break;
                }
            }
            ans[cas] = n - pos + 1;
        } else {
            if (a[2] == a[1]) {
                ans[cas] = n;
            }
            else {
                bool flag = 0;
                for ( int i = 2 ; i <= n ; i++ ) {
                    if ( a[i] == a[i-1] ) {
                        flag = 1;
                        break;
                    }
                }
                if (flag )
                    ans[cas] = n;
                else ans[cas] = n+1;
            }
        }
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i] << endl;
}