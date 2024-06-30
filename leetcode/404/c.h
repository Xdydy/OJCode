#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int dp[1005][1005];
class Solution {
private:
public:
    int maximumLength(vector<int>& nums, int k) {
        for (auto &x : nums ) {
            x %= k;
        }
        map<int,vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            mp[x].push_back(i);
        }
        int cnt1 = 0;
        for (int i = 0; i < k; i++) {
            cnt1 = max(cnt1, (int)mp[i].size());
        }


        int cnt2 = 0 ;
        memset(dp,0,sizeof(dp));
        map<int,int> mp2;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--) {
            for (int j = 0; j < k; j++) {
                if (mp2.find(j) == mp2.end()) {
                    dp[i][j] = n;
                } else {
                    dp[i][j] = mp2[j];
                }
            }
            mp2[nums[i]] = i;
        }
        for (int i = 0 ; i < k; i++) {
            for (int j = 0; j < k ; j++) {
                if (i == j) continue;
                int tmp = 1;
                int cur = mp2[i];
                while(cur != n) {
                    if (tmp % 2) {
                        if (dp[cur][j] != n) {
                            cur = dp[cur][j];
                            tmp++;
                        } else {
                            break;
                        }
                    } else {
                        if (dp[cur][i] != n) {
                            cur = dp[cur][i];
                            tmp++;
                        } else {
                            break;
                        }
                    }
                }
                cnt2 = max(cnt2, tmp);
            }
        }
        return max(cnt1, cnt2);
    }
};