#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(5e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    int target;
    map<int,int> dp[35][2];
    int dfs(int s, int jump, bool back) {
        if (dp[jump][back].find(s) != dp[jump][back].end()) {
            return dp[jump][back][s];
        }
        if (s > target) {
            if (!back) {
                dp[jump][back][s] = 0;
                return 0;
            }
        }
        int res = 0;
        if (s == target) {
            res++;
        } 

        if (back) {
            res += dfs(s-1, jump, false);
        }
        if (s <= target) {
            res += dfs(s+(1<<jump), jump+1, true);
        }
        
        dp[jump][back][s] = res;
        return res;
    }
public:
    int waysToReachStair(int k) {
        target = k;
        return dfs(1,0,true);
    }
};