#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long
const LL INF = 1ll << 60;
const int inf = 1 << 30;

struct Edge {
    int from , to , dist;
};
struct Bellman_Ford {
    int n , m;
    vector <Edge> edges;
    vector <int> G[max_size];
    bool inq[max_size];
    int d[max_size];
    int p[max_size];
    int cnt[max_size];

    void init( int n ) {
        this -> n = n;
        for ( int i = 0 ; i < n ; i++ ) G[i].clear();
        edges.clear();
    }

    void Addedge ( int from , int to , int dist ) {
        edges.push_back((Edge){from , to , dist });
        m = edges.size();
        G[from].push_back(m-1);
    }

    bool negativeCycle () {
        queue <int> Q;
        memset ( inq , 0 , sizeof(inq) );
        memset ( cnt , 0 , sizeof(cnt) );
        for ( int i = 0 ; i < n ; i++ ) { d[i] = 0 ; inq[0] = true ; Q.push(i) ;}

        while (!Q.empty()) {
            int u = Q.front() ; Q.pop();
            inq[u] = false;
            for ( int i = 0 ; i < G[u].size() ; i++ ) {
                Edge& e = edges[G[u][i]];
                if ( d[e.to] > d[u] + e.dist ) {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    if ( !inq[e.to] ) { Q.push(e.to) ; inq[e.to] = true; if ( ++cnt[e.to] > n ) return true; }
                }
            }
        }
        return false;
    }
};