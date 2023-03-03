#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n ;
int a[maxn],b[maxn];
int p[maxn];
vector<pair<int,int>> ans;
pair<int,int> node[maxn];
int dfs = 1;
int cnt = 0;

void solve(int v) {
    int u = a[dfs];
    b[v] -= b[u];
    if ( b[u] == 1 ) {
        cnt++;
        if ( v != -1 ) {
            int minx = min(u,v);
            int maxx = max(u,v);
            ans.push_back({minx,maxx});
        }
        return;
    } else {
        while(b[u] != 1) {
            dfs++;
            solve(u);
        }
        cnt++;
        if ( v != -1 ) {
            int minx = min(u,v);
            int maxx = max(u,v);
            ans.push_back({minx,maxx});
        }   
    }

}

int main () {
    IOS;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> a[i];
        node[a[i]].first = i;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> b[i];
        node[i].second = b[i];
    }
    for ( int i = 2 ; i <= n ; i++ ) {
        p[i] = i-1;
    }
    solve(-1);
    sort(ans.begin(),ans.end());
    for ( auto ss : ans ) {
        cout << ss.first << ' ' << ss.second << "\n";
    }
}