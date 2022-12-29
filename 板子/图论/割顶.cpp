#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long
const LL INF = 1ll << 60;
const int inf = 1 << 30;

int dfs_clock;
int pre[max_size] , low[max_size];
bool iscut[max_size];
vector <int> G[max_size];
int dfs ( int u , int fa ) {
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for ( int i = 0 ; i < G[u].size() ; i++ ) {
        int v = G[u][i];
        if ( !pre[v] ) {
            child++;
            int lowv = dfs ( v , u );
            lowu = min ( lowu , lowv );
            if ( lowv >= pre[u] ) 
                iscut[u] = true;
        }
        else if ( pre[v] < pre[u] && v != fa )
            lowu = min ( lowu , pre[v] );
    }
    if ( fa < 0 && child == 1 ) iscut[u] = 0;
    low[u] = lowu;
    return lowu;
}