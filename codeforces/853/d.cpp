#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
string s, t;
int a[maxn], b[maxn];
vector<int> tmp;

void getTmp() {
    tmp.clear();
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            tmp.push_back(i);
        }
    }
}

void solve() {
    cin >> n;
    cin >> s;
    cin >> t;
    s = ' ' + s;
    t = ' ' + t;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i] - '0';
        b[i] = t[i] - '0';
    }
    getTmp();
    vector<int> ans;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i])
            continue;
        if (a[i]) {
            if (tmp.size() && tmp.front() < i) {
                int dis = i - tmp.front();
                ans.push_back(-dis);
                for (int x : tmp) {
                    if (x + dis <= n) {
                        a[x + dis] ^= 1;
                    }
                }
                getTmp();
            } else {
                flag = 0;
                break;
            }
        } else {
            if (tmp.size()) {
                int dis = tmp.front() - i;
                ans.push_back(dis);
                for (int x : tmp) {
                    if (x - dis <= n) {
                        a[x - dis] ^= 1;
                    }
                }
                getTmp();
            } else {
                flag = 0;
                break;
            }
        }
    }
    if (flag) {
        cout << ans.size() << endl;
        if (ans.size() == 0)
            return;
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        getTmp();
        ans.clear();
        flag = 1;
        for (int i = n; i >= 1; i--) {
            if (a[i] == b[i])
                continue;
            if (a[i]) {
                if (tmp.size() && tmp.back() > i) {
                    int dis = tmp.back() - i;
                    ans.push_back(dis);
                    for (int x : tmp) {
                        if (x - dis >= 1) {
                            a[x - dis] ^= 1;
                        }
                    }
                    getTmp();
                } else {
                    flag = 0;
                    break;
                }
            } else {
                if (tmp.size()) {
                    int dis = tmp.back() - i;
                    ans.push_back(dis);
                    for (int x : tmp) {
                        if (x - dis >= 1) {
                            a[x - dis] ^= 1;
                        }
                    }
                    getTmp();
                } else {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) {
            cout << ans.size() << endl;
            if (ans.size() == 0)
                return;
            for (int x : ans) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        solve();
    }
}