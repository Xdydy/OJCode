#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int dc[4] = {1,0,-1,0};
        int dr[4] = {0,1,0,-1};
        int dir = 0;
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        auto judge = [&](int x, int y) -> bool {
            if (x >= n || x < 0) return false;
            if (y >= m || y < 0) return false;
            if (matrix[x][y] == 101) return false;
            return true;
        };
        int curx = 0, cury= 0 ;
        while(1) {
            // cout << curx << " " << cury << endl;
            if (!judge(curx,cury)) {
                break;
            }
            int x = matrix[curx][cury];
            ans.push_back(x);
            matrix[curx][cury] = 101;
            if (!judge(curx+dr[dir], cury+dc[dir])) {
                dir++;
                dir %= 4;
            }
            curx += dr[dir];
            cury += dc[dir];
        }
        return ans;
    }
};