#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    long long minimumSteps(string s) {
        ll ans = 0 ;
        int n = s.length();
        s = ' ' + s;
        vector<int> v;
        for ( int i = 1; i <= n ; i++ ) {
            if (s[i] == '0') {
                v.push_back(i);
            }
        }

        for ( int i = 0 ; i < v.size() ; i++ ) {
            int tar = i+1;
            int cur = v[i];
            ans += cur - tar;
        }
        return ans;
    }
};