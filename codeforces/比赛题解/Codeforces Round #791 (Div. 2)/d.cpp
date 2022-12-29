#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n , m ;
ll k;
int a[maxn];
struct node
{
    int val;
    int no;
    bool operator < (const node& rhs) const {
        return val < rhs.val;
    }
}Node[maxn];

struct edge {
    int from , to;
}Edge[maxn];

vector<int> G[maxn];
int vis[maxn];
int deg[maxn];
int val[maxn];

bool topo(int mid) {
    bool flag = 0;
    queue<int> q;
    for ( int i = 1 ; i <= mid ; i++ ) {
        int no = Node[i].no;
        if ( deg[no] == 0 ) {
            flag = 1;
            q.push(no);
            val[no] = 1;
        }
    }
    if (!flag) return true;
    while(q.size()) {
        auto top = q.front();
        q.pop();
        for ( int v : G[top] ) {
            if (--deg[v] == 0 ) {
                q.push(v);
            }
            val[v] = max(val[v], val[top]+1);
        }
    }

    int maxx = 0 ;
    for ( int i = 1 ; i <= mid ; i++ ) {
        int no = Node[i].no;
        if ( deg[no] ) {
            flag = 0;
            break;
        }
        maxx = max(maxx, val[no]);
    }
    if (!flag) return true;
    else {
        return maxx >= k;
    }

}


bool check(int mid) {
    for ( int i = 1 ; i <= n ; i++ ) G[i].clear();
    memset(vis, 0, sizeof(int)*(n+5));
    memset(deg, 0, sizeof(int)*(n+5));
    memset(val, 0, sizeof(int)*(n+5));
    for ( int i = 1 ; i <= mid ; i++ ) vis[Node[i].no] = 1;
    for ( int i = 1 ; i <= m ; i++ ) {
        auto e = Edge[i];
        if ( vis[e.from] && vis[e.to] ) {
            G[e.from].push_back(e.to);
            deg[e.to]++;
        }
    }
    return topo(mid);
}


int main () {
    IOS;
    cin >> n >> m >> k;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> a[i];
        Node[i] = {a[i], i};
    }
    sort(Node+1, Node+1+n);

    for ( int i = 1 ; i <= m ; i++ ) {
        int u , v;
        cin >> u >> v;
        Edge[i] = {u,v};
    }

    int left = 1 , right = n+1;
    while(left < right) {
        int mid = left + right >> 1;
        if ( check(mid) ) {
            right = mid;
        }
        else left = mid+1;
    }
    if ( left == n+1 ) {
        cout << -1 << endl;
    }
    else cout << Node[right].val << endl;


}