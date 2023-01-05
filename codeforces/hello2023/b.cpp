#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int ans[maxn];

void solve() {
    cin >> n;
    if (n == 3) {
        cout << "NO" << endl;
    } else if (n & 1) {
        cout << "YES" << endl;
        int x = 3 - n;
        int y = n - 1;
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                cout << x << " ";
            } else {
                cout << y << " ";
            }
        }
        cout << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                cout << 1 << " ";
            } else {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}