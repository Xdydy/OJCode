#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        stack<pair<int,int>> st;
        int ans= 0 ;
        for (int i = 0; i < n; i++) {
            int x = height[i];
            while(st.size() && st.top().first < x) {
                int cur = st.top().first;
                st.pop();
                if (st.size()) {
                    int d = min(x, st.top().first) - cur;
                    ans += d*(i-st.top().second-1);
                }
            }
            st.push({x,i});
        }
        return ans;
    }
};