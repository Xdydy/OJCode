#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
        bool vis[105];
        memset(vis, 0, sizeof(vis));
        int n = fruits.size();
        int ans = 0 ;
        for (int i = 0; i < n; i++) {
            bool flag = 0;
            for (int j = 0; j < n; j++) {
                if (!vis[j] && fruits[i] <= baskets[j]) {
                    vis[j] = 1;
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                ans++;
            }
        }
        return ans;
    }
};