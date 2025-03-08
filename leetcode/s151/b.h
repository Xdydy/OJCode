#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    int countArrays(vector<int> &original, vector<vector<int>> &bounds) {
        int n = original.size();
        int l = -(1<<30), r = 1 << 30;
        for (int i = 0 ; i < n; i++) {
            int u = bounds[i][0];
            int v = bounds[i][1];
            int x = original[i];
            l = max(l, u-x);
            r = min(r, v-x);
        }
        return max(0, r-l+1);
    }
};