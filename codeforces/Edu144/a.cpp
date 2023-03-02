#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
string s;
bool ans[maxn];

int main() {
    IOS;
    string b = "FBFFBFFB";
    b += b;
    b += b;
    b += b;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        cin >> s;
        bool flag = 0;
        for (int i = 0; i+n < b.length(); i++) {
            bool tmp = 1;
            for (int j = 0; j < n; j++) {
                if (b[i + j] != s[j]) {
                    tmp = 0;
                    break;
                }
            }
            if (tmp) {
                flag = 1;
                break;
            }
        }
        ans[cas] = flag;
    }
    for (int i = 1; i <= T; i++)
        if (ans[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
}