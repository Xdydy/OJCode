#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long
const LL INF = 1ll << 60;
const int inf = 1 << 30;

struct Edge {
    int from , to , dist;
};
struct HeapNode {
    int d , u;
    bool operator < ( const HeapNode& rhs ) const {
        return d > rhs.d ;
    }
};
struct Dijkstra {
    int n , m;
    vector <Edge> edges;
    vector <int> G[max_size];
    bool done[max_size];
    int d[max_size];
    int p[max_size];

    void init( int n ) {
        this -> n = n;
        for ( int i = 0 ; i < n ; i++ ) G[i].clear();
        edges.clear();
    }

    void Addedge ( int from , int to , int dist ) {
        edges.push_back((Edge){from,to,dist});
        m = edges.size();
        G[from].push_back(m-1);
    }

    void dijkstra ( int s ) {
        priority_queue <HeapNode> Q;
        for ( int i = 0 ; i < n ; i++ ) d[i] = INF;
        d[s] = 0;
        memset ( done , 0 , sizeof(done) );
        Q.push((HeapNode){0,s});
        while (!Q.empty()) {
            HeapNode x = Q.top() ; Q.pop();
            int u = x.u;
            if ( done[u] ) continue;
            done[u] = true;
            for ( int i = 0 ; i < G[u].size() ; i++ ) {
                Edge& e = edges[G[u][i]];
                if ( d[e.to] > d[u] + e.dist ) {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
};
