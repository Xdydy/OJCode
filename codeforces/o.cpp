#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n , m;
int a[maxn];
int vis[maxn];
int ans[maxn];
int main () {
    IOS;
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];

    for ( int i = 1 ; i <= n ; i++ ) {
        vis[a[i]]++;
    }
    for ( int i = 100000 ; i >= 0 ; i-- ) {
        vis[i] += vis[i+1];
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        int x ; cin >> x;
        ans[i] = vis[x];
    }
    for ( int i = 1 ; i <= m ; i++ )
        cout << ans[i] << endl;
}