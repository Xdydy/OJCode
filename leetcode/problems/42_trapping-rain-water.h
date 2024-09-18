#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<pair<int,int>> st;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            int h = height[i];
            while(st.size() && st.top().first < h) {
                int cur = st.top().first;
                st.pop();
                if (st.empty()) break;
                int l = st.top().second;
                int r = i;
                int d = min(st.top().first, h) - cur;
                ans += d*(r-l-1);
            }
            
            st.push({h,i});
        }
        return ans;
    }
};