#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long
const LL INF = 1ll << 60;
const int inf = 1 << 30;


int W[max_size][max_size] , n;
int Lx[max_size] , Ly[max_size];
int let[max_size];
bool S[max_size] , T[max_size];
bool match ( int i ) {
    S[i] = true;
    for ( int j = i ; j <= n ; j++ ) if ( Lx[i] + Ly[i] == W[i][j] && !T[j] ) {
        T[j] = true;
        if ( !let[j] || match(let[j]) ) {
            let[j] = i;
            return true;
        }
    }
    return false;
}
void update () {
    int a = 1 << 30;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= n ; j++ )
            a = min ( a , Lx[i]+Ly[j] - W[i][j] );
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( S[i] ) Lx[i] -= a;
        if ( T[i] ) Ly[i] += a;
    }
}
void KM () {
    for ( int i = 1 ; i <= n ; i++ ) {
        let[i] = Lx[i] = Ly[i] = 0;
        for ( int j = 1 ; j <= n ; j++ )
            Lx[i] = max ( Lx[i] , W[i][j] );
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        for(;;) {
            for ( int j = 1 ; j <= n ; j++ ) S[j] = T[j] = 0;
            if ( match(i) ) break; else update();
        }
    }
}

