#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

const ll mod = 1e9+7;
int n ;
int a[3005];
ll to[3005];
void getTwo() {
    to[0] = 1;
    for ( int i = 1 ; i <= 3003 ; i++ ) {
        to[i] = to[i-1] * 2 % mod;
    }
}
ll dp[3005][3005];

int main () {
    cin >> n ;
    getTwo();
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    a[n+1] = 1<<30;
    ll ans = 0;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = i+1 ; j <= n ; j++ ) {
            ll res = 1;
            int dis = a[j]-a[i];
            int pos = lower_bound(a+1,a+1+n,a[j]+dis) - a;
            res *= to[n-pos+1];
            res %= mod;
            int pos2 = lower_bound(a+1,a+1+n,a[i]-dis)-a-1;
            res *= to[pos2];
            res %= mod;
            // cout << i << " " << j << " " << pos << " " << pos2 << " " <<  res <<  endl;
            ans += res;
            ans %= mod;
        }
    }
    cout << ans << endl;
}