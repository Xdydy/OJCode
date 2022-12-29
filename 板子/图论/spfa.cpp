#include<bits/stdc++.h>
using namespace std;
#define max_size (int)(1e6+10)
#define LL long long

struct Edge {
    int from , to , dist;
};
struct SPFA {
    int n , m ;
    vector <int> G[max_size];
    vector <Edge> edges;
    int d[max_size];
    bool vis[max_size];

    void init( int n ) {
        this -> n = n;
        for ( int i = 0 ; i <= n ; i++ ) G[i].clear();
    }

    void addedge ( int from , int to , int dist ) {
        edges.push_back((Edge){from,to,dist});
        m = edges.size();
        G[from].push_back(m-1);
    }

    void spfa ( int s )
    {
        queue <int> Q;
        vis[s] = 1;
        d[s] = 0;
        Q.push(s);

        while (!Q.empty())
        {
            int u = Q.front();Q.pop();
            vis[u] = 0;
            for ( int i = 0 ; i < G[u].size() ; i++ )
            {
                Edge &e = edges[G[u][i]];
                if ( d[e.to] >= d[e.from] + e.dist )
                {
                    d[e.to] = d[e.from] + e.dist;
                    if ( !vis[e.to] )
                    {
                        vis[e.to] = 1;
                        Q.push(e.to);
                    }
                }
            }
        }
    }
};