#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
int ans[maxn];

int cnt[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        memset(cnt, 0, sizeof(int) * (n + 5));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            if (a[i] <= n) {
                cnt[a[i]]++;
            }
        }
        int maxx = 0;
        for (int i = 1; i <= n; i++) {
            int tmp= 0 ;
            for (int j = 1; j * j <= i; j++) {
                if (i % j)
                    continue;
                int k = i / j;
                if (j == k) {
                    tmp += cnt[j];
                } else {
                    tmp += cnt[j] + cnt[k];
                }
            }
            maxx = max(maxx,tmp);
        }
        ans[cas] = maxx;
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i] << endl;
}