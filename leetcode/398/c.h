#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    int a[15][10];
public:
    long long sumDigitDifferences(vector<int>& nums) {
        memset(a,0,sizeof(a));
        for (auto x : nums) {
            int cnt = 0 ;
            while(x) {
                a[cnt][x%10]++;
                x /= 10;
                cnt++;
            }
        }
        ll res = 0;
        for (int i = 0; i <= 11; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = j+1; k <= 9; k++) {
                    res += a[i][j] * a[i][k];
                }
            }
        }
        return res;
    }
};