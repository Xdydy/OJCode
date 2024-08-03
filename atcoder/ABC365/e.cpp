#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(2e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
int b[maxn][32];
int pre[maxn][32];

int main () {
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    for ( int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            b[i][j] = (1 << j) & a[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            pre[i][j] = pre[i-1][j] + b[i][j];
        }
    }

    ll res = 0;
    for (int i = 0; i < 30; i++) {
        ll sum0 = 0, sum1 = 0;
        int cnt0 = 0, cnt1 = 0;
        int last = 0;
        int ack = 0;
        for (int j = 1; j <= n; j++) {
            if (b[j][i]) {
                if (ack) {
                    res += sum1 * (1 << i);
                } else {
                    res += sum0 * (1 << i);
                }
            } else {
                if (ack) {
                    res += sum0 * (1 << i);
                } else {
                    res += sum1 * (1 << i);
                }
            }
            if (ack) {
                cnt1++;
                sum1 += 1;
            } else {
                cnt0++;
                sum0 += 1;
            }
            if (b[j][i]) {
                ack ^= 1;
            }
        }
    }
    cout << res << endl;

}
// 0 0 1 0 0 1 0 0 1