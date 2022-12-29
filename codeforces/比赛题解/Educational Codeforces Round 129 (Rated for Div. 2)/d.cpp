#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n ;
ll x;

int check(ll x) {
    int cnt = 0 ;
    while(x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int ans = -1;

map<ll,int> mp;
void dfs(ll u, int dep) {
    if ( mp.find(u) != mp.end() && mp[u] <= dep ) {
        return;
    }
    if ( check(u) > n ) return;
    if ( check(u) == n ) {
        if ( ans == -1 ) ans = dep;
        else ans = min(ans, dep);
        return ;
    }
    mp[u] = dep;

    vector<int> v;
    ll tmp = u ;
    while (tmp)
    {
        v.push_back(tmp % 10);
        tmp /= 10;
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());
    
    for ( int x : v ) {
        dfs(u*x, dep+1);
    }

}


int main () {
    cin >> n >> x;
    dfs(x,0);
    cout << ans << endl;
}