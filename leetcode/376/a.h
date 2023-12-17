#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    int cnt[maxn];
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(cnt,0,sizeof(cnt));
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                int x = grid[i][j];
                cnt[x]++;
            }
        }
        int a = -1, b = -1;
        int x = 1;
        while(a == -1 || b == -1) {
            if (cnt[x] == 2) {
                a = x;
            } else if (cnt[x] == 0) {
                b = x;
            }
            x++;
        }
        vector<int> ans = {a,b};
        return ans;
    }
};