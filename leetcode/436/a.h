#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            int r = i, c = 0 ;
            vector<int> v;
            while(r < n && c < n) {
                v.push_back(grid[r][c]);
                r++, c++;
            }
            sort(v.begin(), v.end(), greater<int>());
            r = i, c = 0;
            while(r < n && c < n) {
                grid[r][c] = v[c];
                r++, c++;
            }

            if (i >= 1) {
                v.clear();
                r = 0, c = i;
                while(r < n && c < n) {
                    v.push_back(grid[r][c]);
                    r++, c++;
                }
                sort(v.begin(), v.end());
                r = 0, c = i;
                while(r < n && c < n) {
                    grid[r][c] = v[r];
                    r++, c++;
                }
            }
        }
        
        return grid;
    }
};