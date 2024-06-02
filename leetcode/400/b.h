#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int,int>> v;
        for (auto meet: meetings) {
            int st = meet[0];
            int ed = meet[1];
            v.push_back({st,ed});
        }
        sort(v.begin(), v.end());
        int l = 0,r = -1;
        int ans = 0 ;
        for (int i = 0;i < v.size(); i++) {
            if (v[i].first > r) {
                ans += (r-l+1);
                l = v[i].first;
                r = v[i].second;
            } else {
                r = max(r, v[i].second);
            }

        }
        ans += (r-l+1);
        return days-ans;
    }
};