#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,m;
int a[maxn];
ll ans[maxn];
int cnt[maxn];
vector<pair<int,int>> val[maxn];

ll getSum(int l, int r, int cur) {
    ll len = r-l+1;
    return m*len-(len-1)*len/2-len*cur;
}


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n >> m;
        for ( int i = 1 ; i <= n ; i++ ) {
            cin >> a[i];
        }
        for ( int i = 1 ; i <= n+m ; i++ ) {
            val[i].clear();
        }
        memset(cnt,0,sizeof(int)*(n+5+m));
        map<int,int> mp;
        for ( int i = 1 ; i <= n ; i++ ) {
            mp[a[i]] = 0;

            cnt[a[i]]++;
        }

        for ( int i = 1 ; i <= m ; i++ ) {
            int p , v;
            cin >> p >> v;
            if ( a[p] == v ) continue;
            val[a[p]].push_back({mp[a[p]],i-1});
            mp.erase(a[p]);
            mp[v] = i;
            a[p] = v;


        }
        for ( auto x : mp ) {
            val[x.first].push_back({x.second,m});
        }
        ll res = 0 ;
        for ( int i = 1 ; i <= n+m ; i++ ) {
            int cur = 0;
            for ( auto ss : val[i] ) {
                int l = ss.first;
                int r = ss.second;
                res += getSum(l,r,cur);
                cur += r-l+1;
            }
        }
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}