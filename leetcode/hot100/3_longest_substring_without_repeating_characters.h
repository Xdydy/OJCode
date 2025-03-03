#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
private:
    int cnt[200];
    bool judge() {
        for (int i = 0; i < 200; i++) {
            if (cnt[i] >= 2 ) {
                return false;
            }
        }
        return true;
    }
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        memset(cnt, 0, sizeof(cnt));
        int l = 0, r = 0;
        int ans = r - l + 1;
        cnt[s[l]]++;
        while(r < n) {
            while(r < n && judge()) {
                ans = max(ans, r-l+1);
                r++;
                cnt[s[r]]++;
            }
            if (r == n) {
                break;
            }
            while(l <= r && !judge()) {
                cnt[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};