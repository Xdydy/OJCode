#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int n;
int a[maxn];

int pre[maxn];
int suf[maxn];
bool vis[maxn];
void solve() {
    memset(pre,0,sizeof(int)*(n+5));
    memset(suf,0,sizeof(int)*(n+5));
    memset(vis,0,sizeof(bool)*(n+5));
    int mex = 0;
    for (int i = 1; i <= n; i++) {
        vis[a[i]] = 1;
        while(vis[mex]) {
            mex++;
        }
        pre[i] = mex;
    }
    mex = 0 ;
    memset(vis,0,sizeof(bool)*(n+5));
    for (int i = n; i >=1 ; i--) {
        vis[a[i]] = 1;
        while(vis[mex]) {
            mex++;
        }
        suf[i] = mex;
    }
    int pos = -1;
    for (int i = 1; i < n ; i++) {
        if (pre[i] == suf[i+1]) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << -1 << endl;
    } else {
        cout << 2 << endl;
        cout << 1 << " " << pos << endl;
        cout << pos+1 << " " << n << endl;
    }
}

int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        solve();
    }
    
}