#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int minOperations(int k) {
        int ans = 1e5;
        for (int i = 0; i <= k-1; i++) {
            int cur = 1+i;
            int cnt = (k-cur) / cur;
            if ((k-cur) % cur) {
                cnt++;
            }
            ans = min(ans, i+cnt);
        }
        return ans;
    }
};