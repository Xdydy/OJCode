#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(2e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
string t;
ll hash1[maxn], hash2[maxn];
ll f[maxn];
void getHash() {
    hash1[0] = hash2[2 * n + 1] = 0;
    f[0] = 1;
    for (int i = 1; i <= 2 * n; i++) {
        hash1[i] = hash1[i - 1] * 131 + t[i] - 'a' + 1;
        f[i] = f[i - 1] * 131;
    }
    for (int i = 2 * n; i >= 1; i--) {
        hash2[i] = hash2[i + 1] * 131 + t[i] - 'a' + 1;
    }
}

ll getHash1(int l, int r) {
    return hash1[r] - hash1[l-1] * f[r-l+1];
}

ll getHash2(int l, int r) {
    return hash2[l] - hash2[r+1]*f[r-l+1];
}

int main() {
    cin >> n;
    cin >> t;
    t = ' ' + t;
    int pos = -1;
    getHash();
    string ans;
    for (int i = 1; i <= n; i++) {
        if (getHash1(1, i) == getHash2(n + 1, i + n)) {
            if (i == n || getHash1(i + 1, n) == getHash2(n + i + 1, 2 * n)) {
                for (int j = i + 1; j <= i + n ; j++)
                    ans += t[j];
                reverse(ans.begin(), ans.end());
                pos = i;
                break;
            }
        }
    }
    if (ans.size()) {
        cout << ans << endl;
        cout << pos << endl;
    } else {
        cout << -1 << endl;
    }
}