#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

char mp[10][10];
string ans[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        for (int i = 1; i <= 8; i++) {
            cin >> mp[i] + 1;
        }
        bool flag = 0;
        string res;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (mp[i][j] !='.') {
                    flag = 1;
                    // cout << i << " " << j << endl;
                    for ( int k = i ; k <= 8 && mp[k][j] != '.' ; k++ ) {
                        res += mp[k][j];
                    }
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ ) {
        cout << ans[i] << endl;
    }
}