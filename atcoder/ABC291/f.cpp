#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n ,m;
vector<int> G[maxn];
vector<int> vG[maxn];
string a[maxn];
int dp[maxn];
int dp2[maxn];

struct node {
    int no;
    int dis;
    bool operator < ( const node& rhs ) const {
        return dis > rhs.dis;
    }
};

void Dijkstra() {
    memset(dp,0x3f,sizeof(dp));
    priority_queue<node> pq;
    pq.push({1,0});
    dp[1] = 0 ;
    while(pq.size()) {
        auto top = pq.top();
        pq.pop();
        int u = top.no;
        int dis = top.dis;
        for ( auto v : G[u] ) {
            if ( dis + 1 < dp[v] ) {
                dp[v] = dis+1;
                pq.push({v,dp[v]});
            }
        }
    }
}

void Dijkstra2() {
    memset(dp2,0x3f,sizeof(dp2));
    priority_queue<node> pq;
    pq.push({n,0});
    dp2[n] = 0 ;
    while(pq.size()) {
        auto top = pq.top();
        pq.pop();
        int u = top.no;
        int dis = top.dis;
        for ( auto v : vG[u] ) {
            if ( dis + 1 < dp2[v] ) {
                dp2[v] = dis+1;
                pq.push({v,dp2[v]});
            }
        }
    }
}

int main () {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ ) {
        string s;
        cin >> s;
        s = ' ' + s;
        a[i] = s;
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( s[j] == '1' ) {
                G[i].push_back(i+j);
                vG[i+j].push_back(i);
            }
        }
    }

    Dijkstra();
    Dijkstra2();
    // for ( int i = 1 ; i <= n ; i++ ) {
    //     cout << i << " " << dp[i] << endl;
    // }
    // cout << endl;
    // for ( int i = 1 ; i <= n ; i++ ) {
    //     cout << i << " " << dp2[i] << endl;
    // }
    for ( int i = 2 ; i < n ; i++ ) {
        int minx = n+1;
        for ( int j = i-1 ; j+m > i && j >= 1 ; j-- ) {
            for ( int k = i+1 ; k-j <= m && k <= n ; k++ ) {
                if ( a[j][k-j] == '1' ) {
                    minx = min(minx, dp[j] + dp2[k] + 1);
                }
            }
        }
        if (minx == n+1) {
            cout << -1 << " ";
        } else {
            cout << minx << " ";
        }
    }
    cout << endl;
}