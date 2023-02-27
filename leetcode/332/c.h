#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
private:
    ll getNum(string s) {
        ll res = 0 ;
        for ( auto x : s ) {
            res = res * 2 + x-'0';
        }
        return res;
    }
public:
    vector<vector<int>> substringXorQueries(string s,
                                            vector<vector<int>> &queries) {
        map<ll, int> mp[35];
        for (int len = 1; len <= 33; len++) {
            for (int i = 0; i+len-1 < s.length(); i++) {
                int st = i;
                int ed = i+len-1;
                string tmp;
                for ( int j = st ; j <= ed ; j++ ) {
                    tmp += s[j];
                }
                ll tmp2 = getNum(tmp);
                if ( mp[len].find(tmp2) == mp[len].end()) {
                    mp[len][tmp2] = i;
                }
            }
        }
        vector<vector<int>> ans;
        for ( auto ss : queries ) {
            int first = ss[0];
            int second = ss[1];
            ll tmp = first^second;
            int len = 1;
            while((1ll<<len) <= tmp) {
                len++;
            }
            if ( mp[len].find(tmp) != mp[len].end() )
                ans.push_back({mp[len][tmp],mp[len][tmp]+len-1});
            else 
                ans.push_back({-1,-1});
        }
        return ans;
    }
};