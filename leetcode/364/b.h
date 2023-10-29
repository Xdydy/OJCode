#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        ll maxx = 0;
        for ( int i = 0 ; i < n ; i++ ) {
            ll sum = 0;
            sum += maxHeights[i];
            ll cur = maxHeights[i];
            for ( int j = i-1 ; j >= 0 ; j-- ) {
                cur = min(1ll*maxHeights[j], cur);
                sum += cur;
            }
            cur = maxHeights[i];
            for ( int j = i+1 ; j < n ; j++ ) {
                cur = min(1ll*maxHeights[j], cur);
                sum += cur;
            }
            maxx = max(maxx , sum);
        }
        return maxx;
    }
};