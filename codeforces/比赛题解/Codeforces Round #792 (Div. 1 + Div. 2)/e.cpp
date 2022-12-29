#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n , k ;
int a[maxn];
int ans[maxn];
int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) {
        cin >> n >> k ;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];

        sort(a+1, a+1+n);
        map<int,int> mp;
        for ( int i = 1 ; i <= n ; i++ ) {
            mp[a[i]]++;
        }
        set<pair<int,int>> s1, s2;
        for ( auto s : mp ) {
            s1.insert({s.second, s.first});
        }
        int hole = 0 ;
        int sum = 0 ;
        int res = 1 << 30;
        for ( int mex = 0 ; mex <= n ; mex++ ) {
            if ( s2.find({mp[mex-1], mex-1}) != s2.end()) {
                sum -= mp[mex-1];
                s2.erase({mp[mex-1], mex-1});
            }
            if ( s1.find({mp[mex-1], mex-1}) != s1.end() ) {
                s1.erase({mp[mex-1], mex-1});
            }

            while(s1.size() && s1.begin()->first + sum <= k) {
                s2.insert(*s1.begin());
                sum += s1.begin()->first;
                s1.erase(s1.begin());
            }
            if ( hole > k ) break;

            int now = mex + s1.size();
            res = min(res, now-mex);

            if ( mp[mex] == 0 ) hole++;
        }
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ ) {
        cout << ans[i] << endl;
    }
}