#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        ll ans = 0 ;
        int left = 0, right = -1;
        ll cur = 0;
        while(right < n) {
            if ( cur < k ) {
                ++right;
                int x = nums[right];
                if ( mp.find(x) == mp.end() ) {
                    mp[x]=0;
                }
                cur += mp[x];
                mp[x]++;
            } else {
                ans += n-right;
                int x = nums[left];
                mp[x]--;
                cur -= mp[x];
                ++left;
            }
        }
        return ans;
    }
};