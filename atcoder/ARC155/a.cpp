#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
ll k;
string s;
bool ans[maxn];

ll hash1[maxn], hash2[maxn];
ll f[maxn];
void Hash() {
    hash1[0] = hash2[n + 1] = 0;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        hash1[i] = hash1[i - 1] * 131 + s[i] - 'a' + 1;
        f[i] = f[i - 1] * 131;
    }
    for (int i = n; i >= 1; i--)
        hash2[i] = hash2[i + 1] * 131 + s[i] - 'a' + 1;
}
ll gethash1(int l, int r) { return hash1[r] - hash1[l - 1] * f[r - l + 1]; }
ll gethash2(int l, int r) { return hash2[l] - hash2[r + 1] * f[r - l + 1]; }

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n >> k;
        cin >> s;
        s = ' ' + s;
        Hash();
        bool flag = 0;
        for (int len = 1; len <= n; len++) {
            if (n % len)
                continue;
            ll res = k + n;
            if (res % (len * 2))
                continue;
            if (len == n) {
                flag = 1;
                break;
            }
            if (gethash1(1, len) != gethash2(len + 1, 2 * len))
                continue;
            int r = len * 2;
            bool tmp = 1;
            while (r * 2 <= n) {
                if (gethash1(1, r) != gethash1(r + 1, 2 * r)) {
                    tmp = 0;
                    break;
                }
                r <<= 1;
            }
            while (r + 2 * len <= n) {
                if (gethash1(1, 2 * len) != gethash1(r + 1, r + 2 * len)) {
                    tmp = 0;
                    break;
                }
                r += 2 * len;
            }
            while (r + len <= n) {
                if (gethash1(1, len) != gethash1(r + 1, r + len)) {
                    tmp = 0;
                    break;
                }
                r += len;
            }
            // if (r < n) {
            //     if (gethash1(1, n-r) != gethash1(r + 1, n)) {
            //         tmp = 0;
            //     }
            // }
            if (tmp) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            for (int len = 1; len <= n; len++) {
                if (n % len)
                    continue;
                ll res = n + k;
                if (res % len)
                    continue;
                if (gethash1(1, len) != gethash2(1, len))
                    continue;
                int r = len;
                bool tmp = 1;
                while (r * 2 <= n) {
                    if (gethash1(1, r) != gethash1(r + 1, 2 * r)) {
                        tmp = 0;
                        break;
                    }
                    r <<= 1;
                }
                while (r + len <= n) {
                    if (gethash1(1, len) != gethash1(r + 1, r + len)) {
                        tmp = 0;
                        break;
                    }
                    r += len;
                }
                if (tmp) {
                    flag = 1;
                    break;
                }
            }
        }

        ans[cas] = flag;
    }
    for (int i = 1; i <= T; i++)
        if (ans[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
}