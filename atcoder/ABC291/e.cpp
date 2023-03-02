#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,m;
int deg[maxn];
int in[maxn], out[maxn];
vector<int> G[maxn];
int ans[maxn];

void topo() {
    queue<int> q;
    for ( int i = 1 ; i <= n ; i++ ) if (!in[i]) q.push(i);
    vector<int> res;
    while(q.size()) {
        int u = q.front();
        res.push_back(u);
        q.pop();
        for ( auto v : G[u] ) {
            if (!--in[v]) {
                q.push(v);
            }
        }
    }
    int cur = 1;
    for ( auto x : res ) {
        ans[x] = cur++;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main () {
    cin>> n >> m ;
    for (int i = 1 ; i <= m ; i++ ) {
        int u , v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        sort(G[i].begin(), G[i].end()) ;
        int sz = unique(G[i].begin(),G[i].end()) - G[i].begin();
        G[i].resize(sz);
        out[i] = sz;
        for ( auto v : G[i] ) {
            in[v]++;
        }
    }
    int cnt1 = 0 , cnt2 = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if (!in[i]) {
            cnt1++;
        }
        if (!out[i]) {
            cnt2++;
        }
    }
    if ( cnt1 == 1 && cnt2 == 1 ) {
        cout << "Yes" << endl;
        topo();
    } else {
        cout << "No" << endl; 
    }
}