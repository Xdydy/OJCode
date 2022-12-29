#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n ,m ;
int q;
char mp[1005][1005];

int c[maxn];
int lowbit(int x ) {
    return x & -x;
}
void add(int x, int v) {
    while(x <= 1e6 ) {
        c[x] += v;
        x += lowbit(x);
    }
}
int qry(int x) {
    int ret = 0;
    while(x) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}

int tran(int x, int y) {
    return (y-1)*n + x;
}

int ans[maxn];

int main () {
    IOS;
    cin >> n >> m >> q;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> mp[i]+1;
    }
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( mp[i][j] == '*' ) {
                cnt++;
                add(tran(i,j), 1);
            }
        }
    }

    for ( int i = 1 ; i <= q ; i++ ) {
        int x , y ;
        cin >> x >> y;
        if ( mp[x][y] == '*' ) {
            cnt--;
            add(tran(x,y), -1);
            ans[i] = cnt - qry(cnt);
            mp[x][y] = '.';
        }
        else {
            cnt++;
            add(tran(x,y), 1);
            ans[i] = cnt - qry(cnt);
            mp[x][y] = '*';
        }
    }
    for (int i = 1 ; i <= q ; i++ ) {
        cout << ans[i] << endl;
    }
}