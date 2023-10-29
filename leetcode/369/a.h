#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0 ;
        int cnt[35];
        memset(cnt,0,sizeof(cnt));
        for (int x:nums) {
            for ( int i = 0 ; 1ll << i <= x ; i++ ) {
                if ((x>>i) & 1) {
                    cnt[i]++;
                }
            }
        }
        for ( int i = 0 ; i <= 31 ; i++ ) {
            if (cnt[i] >= k) {
                ans |= (1<<i);
            }
        }
        return ans;
    }
};