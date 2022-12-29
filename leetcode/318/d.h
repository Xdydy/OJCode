#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        n = robot.size() + factory.size() + 2;
        m = 0 ;

        int rsz = robot.size();
        int facsz = factory.size();
        for ( int i = 1 ; i <= robot.size() ; i++ ) {
            ll pos = robot[i-1];
            for ( int j = 1 ; j <= factory.size() ; j++ ) {
                int pos2 = factory[j-1][0];
                ll cost = abs(pos-pos2);
                AddEdge(i,j+rsz,1,cost);
            }
            AddEdge(0,i,1,0);
        }
        for ( int i = 1 ; i <= factory.size() ; i++ ) {
            int li = factory[i-1][1];
            AddEdge(rsz+i,rsz+facsz+1,li,0);
        }
        return Maxcost(0,rsz+facsz+1);
    }
private:
    const ll INF = 1ll<<60;
    struct Edge {
        int from, to;
        ll cap,flow;
        ll cost;
    };

    int n,m;
    vector<Edge> edges;
    vector<int> G[1005];
    ll inq[1005];
    ll d[1005];
    ll p[1005];
    ll a[1005];

    void AddEdge(int from, int to, int cap, ll cost) {
        edges.push_back({from,to,cap,0,cost});
        edges.push_back({to,from,0,0,-cost});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BellmanFord ( int s , int t , ll &flow , ll &cost ) {
        for ( int i = 0 ; i <= n ; i++ ) d[i] = INF;
        memset ( inq , 0 , sizeof(inq) );
        d[s] = 0; inq[s] = 1 ; p[s] = 0 ; a[s] = INF;

        queue <int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front() ; Q.pop();
            inq[u] = 0;
            for ( int i = 0 ; i < G[u].size() ; i++ ) {
                Edge& e = edges[G[u][i]];
                if ( e.cap > e.flow && d[e.to] > d[u] + e.cost ) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min ( a[u] , e.cap - e.flow );
                    if ( !inq[e.to] ) { Q.push(e.to) ; inq[e.to] = 1 ;}
                }
            }
        }
        if ( d[t] == INF ) return false;
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while ( u != s) {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    ll Maxcost ( int s , int t ) {
        ll flow = 0 , cost = 0;
        while ( BellmanFord( s , t , flow , cost ) )
            ;
        return cost;
    }
};