#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long
const LL INF = 1ll << 60;
const int inf = 1 << 30;

int n , m;
int w[max_size] , u[max_size] , v[max_size];
int p[max_size] , r[max_size];
int cmp ( const int i , const int j ) { return w[i] < w[j] ;}
int find ( int x ) { return p[x] == x ? x : p[x] = find(p[x]) ;}
int Kruskal () {
    int ans = 0;
    for ( int i = 0 ; i < n ; i++ ) p[i] = i;
    for ( int i = 0 ; i < m ; i++ ) r[i] = i;
    sort ( r , r+m , cmp );
    for ( int i = 0 ; i < m ; i++ ) {
        int e = r[i] ; int x = find(u[e]) ; int y = find(v[e]);
        if ( x != y ) { ans += w[e] ; p[x] = y ;}
    }
    return ans;
}