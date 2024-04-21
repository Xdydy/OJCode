#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(5e4 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

const ll inf = 1ll << 60;

struct Edge {
    int from, to;
    ll d;
};
struct HeadNode {
    ll d;
    int u;
    bool operator<(const HeadNode &rhs) const { return d > rhs.d; }
};

int n, m;
vector<Edge> edges;
vector<int> G[maxn];
bool done[maxn];
ll d[maxn];
vector<int> p[maxn];
bool vis[maxn];

class Solution {
private:
    void addEdge(int from , int to , ll d ) {
        edges.push_back({from,to,d});
        m = edges.size();
        G[from].push_back(m-1);
    }
public:
    vector<bool> findAnswer(int nz, vector<vector<int>> &_edges) {
        n = nz;
        for (int i = 0; i < n; i++)
            G[i].clear(), p[i].clear();
        edges.clear();

        for (auto edge: _edges) {
            int x = edge[0];
            int y = edge[1];
            ll d = edge[2];
            addEdge(x,y,d);
            addEdge(y,x,d);
        }

        priority_queue<HeadNode> q;
        for (int i = 0; i < n; i++) d[i] = inf;

        d[0] = 0;
        memset(done,0,sizeof(done));
        q.push({0,0});

        while(q.size()) {
            auto top = q.top(); 
            q.pop();
            int u = top.u;
            if (done[u]) continue;
            done[u] = true;
            for (int i = 0; i < G[u].size(); i++) {
                Edge e = edges[G[u][i]];
                if (d[e.to] > d[u] + e.d) {
                    d[e.to] = d[u] + e.d;
                    p[e.to].clear();
                    p[e.to].push_back(G[u][i]);
                    q.push({d[e.to], e.to});
                } else if (d[e.to] == d[u] + e.d) {
                    p[e.to].push_back(G[u][i]);
                    q.push({d[e.to], e.to});
                }
            }
        }
        vector<bool> ans;
        for (int i = 0; i < _edges.size(); i++) {
            ans.push_back(false);
        }
        if (d[n-1] == inf) {
            return ans;
        } else {
            memset(vis, false,sizeof(vis));
            queue<int> res;
            res.push(n-1);
            while(res.size()) {
                auto top = res.front();
                res.pop();
                for (auto e: p[top]) {
                    ans[e/2] = 1;
                    Edge e1 = edges[e];
                    if (vis[e1.from]) {
                        continue;
                    }
                    vis[e1.from] = 1;
                    res.push(e1.from);
                }
            }
            return ans;
        }
    }
};