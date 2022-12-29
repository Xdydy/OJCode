#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
LL a[maxn];
LL ans[maxn];

int u[20];
int v[20];
int maxx ;

void dealLR(LL l, LL r)
{
    for ( LL i = l ; i <= r ; i++ )
    {
        LL x = i;
        int cur = 0;
        while(x)
        {
            if ( x & 1 )
                u[cur]++;
            x >>= 1;
            cur++;
            maxx = max(maxx, cur);
        }
    }
}

void dealA()
{
    for ( int i = 1 ; i <= n ; i++ )
    {
        LL x = a[i];
        int cur = 0;
        while(x)
        {
            if ( x & 1 )
                v[cur]++;
            x >>= 1;
            cur++;
            maxx = max(maxx, cur);
        }
    }
}

int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        LL l , r ;
        cin >> l >> r;
        n = r - l + 1;
        memset(u, 0, sizeof(u));
        memset(v, 0, sizeof(v));
        maxx = 0;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        dealLR(l,r);
        dealA();

        LL res = 0 ;
        for ( int i = 0 ; i <= maxx ; i++ )
        {
            if ( v[i] == u[i] )
            {

            }
            else 
            {
                res |= (1ll << i);
            }
        }
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}