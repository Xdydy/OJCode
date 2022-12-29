#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

const LL mod = 998244353;
LL d[maxn];
vector<LL> fac[maxn];

LL quick_pow(LL x, LL k )
{
    LL res = 1;
    while (k)
    {
        if (k&1) res = res * x % mod;
        k >>= 1;
        x = x * x % mod;
    }
    return res;
}

LL get_inv(LL x) {
    return quick_pow(x, mod-2);
}
int f[maxn];
int wf[maxn];
struct node 
{
    int v , x, y;
};
vector<node> G[maxn];

void dfs1(int u, int fa)
{
    for ( auto ss : G[u] )
    {
        int v = ss.v;
        int x = ss.x;
        int y = ss.y;
        if ( v == fa ) continue;
        for ( auto p : fac[y] )
        {
            f[p]--;
        }
        for ( auto p : fac[x] ) 
        {
            f[p]++;
            wf[p] = max(f[p], wf[p]);
        }

        dfs1(v,u);

        for ( auto p : fac[y] )
            f[p]++;
        for ( auto p : fac[x] )
            f[p]--;
    }
}

LL dfs2(int u, int fa, LL p)
{
    LL res = p;
    LL tmp = p ;
    for ( auto ss : G[u] )
    {
        p = tmp;
        int v = ss.v;
        int x = ss.x;
        int y = ss.y;
        if ( v == fa ) continue;
        for ( auto s : fac[y] ) 
            p = p * s % mod;
        for ( auto s : fac[x] )
            p = p * get_inv(s) % mod;
        res += dfs2(v,u,p);
        res %= mod;
    }
    return res;
}

LL ans[maxn];
int main ()
{
    IOS;
    for ( int i = 0 ; i <= 200005 ; i++ )   
        d[i] = 1;
    for ( int i = 200005 ; i > 1 ; i-- )
        for ( int j = i ; j < 200005 ; j += i )
            d[j] = i;
    for ( int i = 1 ; i < 200005 ; i++ )
        for ( int x = i ; x != 1 ; x /= d[x] )
            fac[i].push_back(d[x]);
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        int n ; cin >> n ;
        set<int> dd;
        for ( int i = 1 ; i <= n ; i++ )
            G[i].clear();
        for ( int i = 1 ; i < n ; i++ )
        {
            int u , v , x,  y;
            cin >> u >> v >> x >> y;
            G[u].push_back({v,x,y});
            G[v].push_back({u,y,x});
            for ( int z : fac[x] )  
                dd.insert(z);
            for ( int z : fac[y] )
                dd.insert(z);
        }

        dfs1(1,-1);
        LL res = 1 ;
        for ( int x : dd )
            for ( int i = 0 ; i < wf[x] ; i++ )
                res = res * x % mod;
        ans[cas] = dfs2(1,-1,res);

        for ( int x : dd )
            f[x] = wf[x] = 0;
    }   
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}