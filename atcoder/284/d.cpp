#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e7 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

ll n;
pair<ll, ll> ans[maxn];

bool mark[maxn];
ll pri[maxn];
int cnt = 0;
void getPri() {
    for (int i = 2; i <= 1e7; i++) {
        if (!mark[i]) {
            pri[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * pri[j] <= 1e7; j++) {
            mark[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}

int main() {
    IOS;
    getPri();
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        for (int i = 1; i <= cnt; i++) {
            if (n % pri[i])
                continue;
            ll x = n/pri[i];
            ll tmp = sqrt(x);
            if (tmp*tmp==x) {
                ans[cas] = {tmp,pri[i]};
            } else {
                tmp = x /  pri[i];
                ans[cas] = {pri[i],tmp};
            }
            // for ( int j = 1 ; j <= cnt && pri[j]*pri[j] <= x; j++ ) {
            //     if (x%pri[j]) continue;
            //     ll k = x / pri[j];
            //     if (pri[j]==pri[i]) {
            //         ans[cas] = {pri[i],k};
            //     } else if ( k == pri[j] ){
            //         ans[cas] = {pri[j],pri[i]};
            //     } else {
            //         ans[cas] = {pri[i],pri[j]};
            //     }
            //     break;
            // }
            break;
        }
        
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i].first << " " << ans[i].second << endl;
}