#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    int vec[15];
    int dp[15][15];
    int solve(int pos, int sum, bool limit) {
        if (pos == 0) return sum;
        if (!limit && dp[pos][sum] != -1) return dp[pos][sum];
        int up = vec[pos];
        if (!limit) up = 9;
        dp[pos][sum] = 0 ;
        for (int i = 0; i <= up; i++) {
            dp[pos][sum] += solve(pos-1, sum + (i==1), limit && (i == vec[pos]));
        }
        return dp[pos][sum];
    }
public:
    int countDigitOne(int n) {
        int cur = 0;
        while(n) {
            int x = n % 10;
            vec[++cur] = x;
            n /= 10;
        }
        for (int i = 0; i <= 10; i++) {
            for (int j = 0; j <= 10; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(cur, 0, 1);
    }
};