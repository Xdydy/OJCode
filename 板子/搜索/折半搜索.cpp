#include <bits/stdc++.h>
using namespace std;
#define LL long long 

const LL INF = 1LL << 60;
int n , m , ans = INF;
map <LL,int> f;
LL a[40];

int main ()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for ( int i = 0 ; i < n ; i++ ) a[i] = ( 1ll << i );
    for ( int i = 1 ; i <= m ; i++ )
    {
        int u , v;
        cin >> u >> v;
        --u , --v;
        a[u] |= ( 1ll << v );
        a[v] |= ( 1ll << u );
    }
    for ( int i = 0 ; i < ( 1<<(n/2) ) ; i++ )
    {
        LL t = 0;
        int cnt = 0;
        for ( int j = 0 ; j < n/2 ; j++ )
        {
            if ( (i >> j) & 1 ) 
            {
                t ^= a[j];
                ++cnt;
            }
        }
        if ( !f.count(t) )
            f[t] = cnt;
        else f[t] = min ( f[t] , cnt );
    }

    for ( int i = 0 ; i < (1 << (n-n/2)) ; i++ )
    {
        LL t = 0;
        int cnt = 0;
        for ( int j = 0 ; j < ( n - n / 2 ) ; j++ )
        {
            if ( (i>>j) & 1 )
            {
                t ^= a[n / 2 + j];
                ++cnt;
            }
        }
        if ( f.count(((1ll<<n)-1)^t) )
            ans = min ( ans , cnt + f[((1ll<<n)-1)^t] );
    }
    cout << ans << endl;
    return 0;
}