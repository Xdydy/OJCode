#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
    int l[maxn];
    int r[maxn];
    ll dp[maxn];
    ll dp2[maxn];
public:
    long long maximumSumOfHeights(vector<int> &maxHeights) {
        stack<pair<int, int>> s;
        int n = maxHeights.size();
        for (int i = 1; i <= n; i++) {
            while (s.size() && s.top().first > maxHeights[i - 1]) {
                r[s.top().second] = i - 1;
                s.pop();
            }
            s.push({maxHeights[i - 1], i});
        }
        while (s.size()) {
            r[s.top().second] = n;
            s.pop();
        }

        for (int i = n; i >= 1; i--) {
            while (s.size() && s.top().first > maxHeights[i - 1]) {
                l[s.top().second] = i + 1;
                s.pop();
            }
            s.push({maxHeights[i-1],i});
        }
        while(s.size()) {
            l[s.top().second] = 1;
            s.pop();
        }


        dp[0] = 0;
        for ( int i = 1 ; i <= n ; i++ ) {
            ll x = maxHeights[i-1];
            dp[i] = x*(i-l[i]+1) + dp[l[i]-1];
        }

        dp2[n+1] = 0 ;
        for ( int i = n ; i >= 1 ; i-- ) {
            ll x = maxHeights[i-1];
            dp2[i] = x*(r[i]-i+1) + dp2[r[i]+1];
        }

        ll maxx = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            maxx = max(maxx, dp[i]+dp2[i] - maxHeights[i-1]);
        }
        return maxx;
    }
};