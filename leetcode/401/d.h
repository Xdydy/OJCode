#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    bool vis[maxn];
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        memset(vis,0,sizeof(vis));
        vis[0] = 1;
        for (auto x : rewardValues) {
            for (int i = 0; i < x ; i++) {
                vis[i+x] |= vis[i]; 
            }
        }
        int ans = 0;
        for (int i = 100000; i >= 0; i--) {
            if (vis[i]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};