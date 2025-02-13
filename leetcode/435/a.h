#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int maxDifference(string s) {
        int cnt[30];
        memset(cnt,0 ,sizeof(cnt));
        for (auto x : s ) {
            cnt[x-'a']++;
        }
        int max_odd = 0, max_even = 0;
        int min_odd = 1 << 29, min_even = 1<<29;
        for (int i = 0; i < 26; i++) {
            if (!cnt[i]) continue;
            if (cnt[i] & 1) {
                max_odd = max(max_odd, cnt[i]);
                min_odd = min(min_odd, cnt[i]);
            } else {
                max_even = max(max_even, cnt[i]);
                min_even = min(min_even, cnt[i]);
            }
        }
        return max_odd-min_even;
    }
};