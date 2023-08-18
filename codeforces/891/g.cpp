#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

const ll mod = 998244353;

int n;
int S;
ll ans[maxn];
int kids[maxn];
int p[maxn];

struct Edge {
    int u,v;
    ll w;
    bool operator < (const Edge& rhs) const {
        return w < rhs.w;
    }
}edge[maxn];

ll quick_pow(ll x, ll k) {
    ll res = 1;
    while(k) {
        if (k&1) res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}


void init() {
    for ( int i = 1 ; i <= n ; i++ ) {
        p[i] = i;
        kids[i] = 1;
    }
}


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1; cas <=T ; cas++ ) {
        cin >> n >> S;
        init();
        for ( int i = 1 ; i < n ; i++ ) {
            int u,v;
            int w;
            cin >> u >> v >> w;
            edge[i] = {u,v,w};
        }
        sort(edge+1,edge+n);
        ll res = 1;
        for ( int i = 1 ; i < n ; i++ ) {
            auto e = edge[i];
            int u = e.u;
            int v = e.v;
            int w = e.w;
            int x = find(u);
            int y = find(v);
            ll tmp = quick_pow(S-w+1,1ll*kids[x]*kids[y]-1);
            res *= tmp;
            res %= mod;

            p[x] = y;
            kids[y] += kids[x];
        }
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ ) {
        cout << ans[i] << "\n";
    }
}
