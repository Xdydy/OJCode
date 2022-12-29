#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,m,k;
struct node {
    int idx;
    int cnt = 0 ;
    char mp[35][35];
    bool operator < (const node& rhs) const {
        return cnt > rhs.cnt;
    }
}Node[105];

struct op{
    int op;
    int i;
    int r,c;
};

int main () {
    IOS;
    cin >> n >> m >> k;

    for ( int i = 1 ; i <= k+1 ; i++ ) {
        char mp[35][35];
        for ( int r = 1 ; r <= n ; r++ ) {
            cin >> mp[r]+1;
        }
        int cnt = 0 ;
        for ( int r = 2 ; r < n ; r++ ) {
            for ( int c = 2 ; c < m ; c++ ) {
                int dx[] = {-1,1,0,0};
                int dy[] = {0,0,-1,1};
                bool flag = 1;
                for ( int k = 0 ; k < 4 ; k++ ) {
                    int nr = r + dx[k];
                    int nc = c + dy[k];
                    if (mp[nr][nc] == mp[r][c]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    cnt++;
                }
            }
        }
        Node[i].idx = i;
        Node[i].cnt = cnt;
        memcpy(Node[i].mp,mp,sizeof(mp));
    }
    sort(Node+1,Node+2+k);
    cout << Node[1].idx << endl;

    vector<op> ans;
    for ( int i = 1 ; i <= k ; i++ ) {
        node cur = Node[i];
        node nxt = Node[i+1];
        if ( cur.cnt == nxt.cnt ) {
            op tmp;
            tmp.op = 2;
            tmp.i = nxt.idx;
            ans.push_back(tmp);
        } else {
            vector<pair<int,int>> v;
            for ( int r = 1 ; r <= n ; r++ ) {
                for ( int c = 1 ; c <= m ; c++ ) {
                    if (cur.mp[r][c] != nxt.mp[r][c]) {
                        v.push_back({r,c});
                    }
                }
            }
            for ( auto ss : v ) {
                op tmp;
                tmp.op = 1;
                int r = ss.first;
                int c = ss.second;
                tmp.r =r;
                tmp.c=c;
                ans.push_back(tmp);
            }
            op tmp;
            tmp.i = nxt.idx;
            tmp.op = 2;
            ans.push_back(tmp);
        }
    }
    cout << ans.size() << endl;
    for ( auto ss : ans ) {
        if ( ss.op == 1 ) {
            cout << ss.op << " " << ss.r << " " << ss.c << endl;
        } else {
            cout << ss.op << " " << ss.i << endl;
        }
    }
}