#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ll mp[30][30];
        for (int i = 0 ; i <= 28 ; i++ ) {
            for (int j = 0; j <= 28 ; j++ ) {
                if (i ==j) {
                    mp[i][j] = 0;
                } else {
                    mp[i][j] = 1ll<<60;

                }
            }
        }
        int m = original.size();
        for (int i = 0 ; i < m ; i++ ) {
            auto s = original[i];
            auto d = changed[i];
            mp[s-'a'][d-'a'] = min(mp[s-'a'][d-'a'], 1ll*cost[i]);
        }

        for (int k = 0 ; k < 26 ; k++ ) {
            for (int i = 0; i < 26 ; i++ ) {
                for (int j = 0 ; j < 26 ; j++ ) {
                    if (mp[i][k] != 1ll << 60 && mp[k][j] != 1ll<<60) {
                        mp[i][j] = min(mp[i][j], mp[i][k]+mp[k][j]);
                    }
                }
            }
        }
        int n = source.size();
        ll ans = 0;
        bool flag = 1;
        for (int i = 0; i < n ; i++ ) {
            auto s = source[i];
            auto d = target[i];
            if (mp[s-'a'][d-'a'] == 1ll<<60) {
                flag = 0;
                break;
            }
            ans += mp[s-'a'][d-'a'];
        }
        if (!flag) {
            return -1;
        }
        return ans;
    }
};