#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) -> bool{
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<vector<int>> ans;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            while(i < n && intervals[i][0] <= r) {
                r = max(intervals[i][1], r);
                i++;
            }
            i--;
            vector<int> tmp = {l,r};
            ans.push_back(tmp);
        }
        return ans;
    }
};