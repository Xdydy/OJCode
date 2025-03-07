#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int pre[55][55];
class Solution {
public:
    int largestInteger(vector<int> &nums, int k) {
        int n = nums.size();
        memset(pre,0,sizeof(pre));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 50; j++) {
                pre[i][j] = pre[i-1][j];
            }
            int x = nums[i-1];
            pre[i][x]++;
        }
        int ans = -1;
        for (int i = 50; i >= 0; i--) {
            int cnt = 0 ;
            for (int j = 1; j+k-1 <= n; j++) {
                int ed = j+k-1;
                if (pre[ed][i] - pre[j-1][i] > 0) {
                    cnt++;
                }
            } 
            if (cnt == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};