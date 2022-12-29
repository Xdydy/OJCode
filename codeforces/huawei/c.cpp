#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int st,ed,ttl;
vector<pair<int,int> > G[505];
int dp[505][305];


int main () {
    cin >> n >> st >> ed >> ttl;
    for ( int i = 1 ; i <= n ; i++ ) {
        int u , v , w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for ( int i = 1 ; i <= 500 ; i++ ) {
        for ( int j = 0 ; j <= 255 ; j++ ) {
            dp[i][j] = 1 << 29;
        }
    }
    queue<pair<int,int> > q;
    q.push({st,ttl});
    dp[st][ttl] = 0;
    while(q.size()) {
        int u = q.front().first;
        int cur = q.front().second;
        q.pop();
        if ( cur == 0 ) continue;
        for ( auto ss : G[u] ) {
            int v = ss.first;
            int w = ss.second;
            // cout << u << " " << v << endl;
            if ( dp[v][cur-1] > dp[u][cur] + w ) {
                q.push({v,cur-1});
                dp[v][cur-1] = dp[u][cur] + w;
            }
        }
    }
    int ans1 = 1 << 29;
    int ans2 = -1;
    for ( int i = 255 ; i >= 0 ; i-- ) {
        if ( dp[ed][i] < ans1 ) {
            ans1 = dp[ed][i];
            ans2 = i;
        }
    }
    if ( ans2 == -1 ) cout << -1 << endl;
    else cout << ans1 << " " << ans2 << endl;
}