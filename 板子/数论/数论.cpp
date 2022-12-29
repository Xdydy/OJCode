#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long
const LL INF = 1ll << 60;
const int inf = 1 << 30;

LL pri[max_size];
LL phi[max_size];
bool vis[max_size];
int cnt = 0;
void get_pri() {
    for ( int i = 2 ; i < max_size ; i++ ) {
        if ( !vis[i] ) pri[cnt++] = i , phi[i] = i-1;
        for ( int j = 0 ; j < cnt && i*pri[j] < max_size ; j++ ) {
            vis[i*pri[j]] = true;
            if ( i % pri[j] == 0 )
            {
                phi[i*pri[j]] = phi[i] * pri[j];
                break;
            }
            phi[i*pri[j]] = phi[i] * ( pri[j] - 1 );
        }
    }
}

////////////////////////////////////////////////////////////////////////////

LL Euler ( LL n ) {
    LL ans = n ;
    for ( int i = 2 ; i*i <= n ; i++ ) {
        if ( n % i == 0 ) {
            ans = ans / i*(i-1);
            while ( n % i == 0 )
                n /= i;
        }
    }
    if ( n > 1 ) ans = ans / n * (n-1);
    return ans;
}

/////////////////////////////////////////////////////////////////////////////

void exgcd ( LL a , LL b , LL& d , LL& x , LL& y ) {
    if (!b) { d = a ; x = 1 ; y = 0; }
    else { exgcd( b , a%b , d , y , x ) ; y -= x*(a/b); }
}
LL get_inv ( LL a , LL n ) {
    LL d , x , y;
    exgcd ( a , n , d , x , y );
    return d == 1 ? (x+n) % n : -1;
}

LL inv[max_size];
void get_inv ( LL MOD )
{
    inv[1] = 1;
    for ( int i = 2 ; i < max_size ; i++ )
        inv[i] = MOD - (LL)MOD/i*inv[MOD%i] % MOD;
}