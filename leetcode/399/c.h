#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    int cnt[maxn];
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> v;
        for (auto x : nums1) {
            if (x % k == 0) {
                v.push_back(x/k);
            }
        }
        memset(cnt,0,sizeof(cnt));
        for (auto x : v) {
            for (int i = 1; i*i <= x; i++) {
                if (x%i) continue;
                int j = x/i;
                cnt[i]++;
                if (i != j) {
                    cnt[j]++;
                }
            }
        }
        ll ans= 0 ;
        for(auto x : nums2) {
            ans += cnt[x];
        }
        return ans;
    }
};