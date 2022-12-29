#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n ;
int a[maxn];
int minx[maxn];

int main () {
    IOS;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];

    minx[0] = 1 << 30;
    for ( int i = 1 ; i <= n ; i++ ) {
        minx[i] = min(minx[i-1], a[i]);
    }

    int ans = 1 << 30;
    for ( int i = 4 ; i <= n ; i++ ) {
        int cnt1 = minx[i-3] / 2 + ( minx[i-3] % 2 );
        int cnt2 = a[i] / 2 + ( a[i] % 2 );
        ans = min(ans, cnt1+cnt2);
    }

    for ( int i = 3 ; i <= n ; i++ ) {
        int cnt1 = a[i-2] / 2 + a[i-2] % 2;
        int cnt2 = a[i] / 2 + a[i] % 2 ;
        int cnt = min(a[i], a[i-2]);
        int rest = max(a[i], a[i-2]) - min(a[i], a[i-2]);
        cnt += rest / 2 + rest % 2;
        cnt = min(cnt, cnt1 + cnt2);
        ans = min(ans, cnt);
    }

    for ( int i = 2 ; i <= n ; i++ ) {
        int mi = min(a[i], a[i-1]);
        int mx = max(a[i], a[i-1]);
        if ( mx >= 2*mi ) {
            ans = min(ans, mx/2+mx%2);
        }
        else {
            int cnt = mx - mi;
            int rest = mi - cnt;
            cnt += rest / 3  * 2;
            if ( rest % 3 == 1 ) {
                cnt++;
            }
            else if ( rest % 3 == 2 ) {
                cnt+=2;
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
}