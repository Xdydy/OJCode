#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    int vis[maxn];
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        for (int i = 1; i <= 1e5; i++) {
            vis[i] = 1 << 29;
        }
        for (int i = 0; i < elements.size(); i++) {
            int x = elements[i];
            vis[x] = min(vis[x], i);
        }

        int maxx = 0;
        for (auto x : groups) {
            maxx = max(maxx, x);
        }
        for (int i = 1; i <= maxx; i++) {
            for (int k = 1; k*k <= i; k++) {
                if (i % k) continue;
                int j = i / k;
                vis[i] = min(vis[i], min(vis[j], vis[k]));
            }
        }
        vector<int> ans;
        for (auto x : groups) {
            if (vis[x] == 1 << 29) {
                ans.push_back(-1);
            } else {
                ans.push_back(vis[x]);
            }
        }
        return ans;
    }
};