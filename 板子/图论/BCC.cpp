#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long
const LL INF = 1ll << 60;
const int inf = 1 << 30;



int pre[max_size] , iscut[max_size] , bccno[max_size] , dfs_clock  , bcc_cnt;
vector <int> G[max_size] , bcc[max_size];
struct Edge {
    int u, v ;
};
stack <Edge> S;

int dfs ( int u , int fa ) {
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for ( int i = 0 ; i < G[u].size() ; i++ ) {
        int v = G[u][i];
        Edge e = (Edge){u,v};
        if ( !pre[v] ) {
            S.push(e);
            child++;
            int lowv = dfs ( u , v );
            lowu = min ( lowu , lowv );
            if ( lowv >= pre[u] ) {
                iscut[u] = true;
                bcc_cnt++ ; bcc[bcc_cnt].clear();
                for (;;) {
                    Edge x = S.top() ; S.pop();
                    if ( bccno[x.u] != bcc_cnt ) { bcc[bcc_cnt].push_back(x.u) ; bccno[x.u] = bcc_cnt ; }
                    if ( bccno[x.u] != bcc_cnt ) { bcc[bcc_cnt].push_back(x.v) ; bccno[x.v] = bcc_cnt ; }
                    if ( x.u == u && x.v == v ) break;
                }
            }
        }
        else if ( pre[v] < pre[u] && v != fa ) {
            S.push(e);
            lowu = min ( lowu , pre[v] );
        }
    }
    if ( fa < 0 && child == 0 ) iscut[u] = 0;
    return lowu;
}
void find_bcc ( int n ) {
    memset ( pre, 0 , sizeof(pre) );
    memset ( bccno , 0 , sizeof(bccno) );
    memset ( iscut , 0 , sizeof(iscut) );
    dfs_clock = bcc_cnt = 0;
    for ( int i = 0 ; i < n ; i++ )
        if (!pre[i]) dfs(i,-1);
}



