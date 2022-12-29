#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int n , m ;

array<ll,3> exgcd(ll a, ll b) {
    if ( b == 0 ) {
        return {a,1,0};
    }
    auto [g,x,y] = exgcd(b,a%b);
    return {g,y,x-a/b*y};
}

ll val[maxn];
ll a[maxn], b[maxn];
ll x[maxn], y[maxn];
ll ans[maxn];

int main () {
    IOS;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i] >> b[i];
    cin >> m ;
    for ( int i = 1 ; i <= m ; i++ ) cin >> x[i] >> y[i];

    ll cur = 0 ;
    priority_queue<ll> pq;
    for ( int i = 1 ; i <= n ; i++ ) {
        cur += b[i];
        pq.push(a[i]-b[i]);
    }

    val[0] = cur;
    for ( int i = 1 ; i <= n ; i++ ) {
        ll top = pq.top();
        val[i] = val[i-1] + top;
        pq.pop();
    }
    ll high = max_element(val+1,val+1+n)-val-1;


    for ( int i = 1 ; i <= m ; i++ ) {
        auto [gcd,u,v] = exgcd(x[i],y[i]);
        if ( n % gcd ) {
            ans[i] = -1;
        } else {
            u = u * (n/gcd) % (y[i]%gcd);
            if ( u < 0 ) {
                u += y[i] / gcd;
            }
            if ( x[i] * u > n ) {
                ans[i] = -1;
            } else {
                ll d = x[i]*y[i]/gcd;
                ll minx = x[i]*u;
                ll maxx = n - (n-x[i]*u) % d;
                ll res = max(val[minx], val[maxx]);
                if ( high > minx && high <= maxx ) {
                    int l = high - (high-minx) % d;
                    int r = high + (maxx - high) % d;
                    res = max({res,val[l],val[r]});
                }
                ans[i] = res;
            }

        }

    }
    for ( int i = 1 ; i <= m ; i++ ) {
        cout << ans[i] << endl;
    }
}