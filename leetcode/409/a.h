#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class neighborSum {
public:
    neighborSum(vector<vector<int>>& grid) {
        grid_ = grid;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for ( int j = 0 ; j < grid[0].size(); j++) {
                int x = grid[i][j];
                mp[x] = {i,j};
            }
        }
    }
    
    int adjacentSum(int value) {
        auto pos = mp[value];
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int d1 = dx[i];
            int d2 = dy[i];
            int x = pos.first;
            int y = pos.second;
            if (judge(x+d1,y+d2)) {
                sum += grid_[x+d1][y+d2];
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        auto pos = mp[value];
        int dx[] = {-1,-1,1,1};
        int dy[] = {-1,1,-1,1};
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int d1 = dx[i];
            int d2 = dy[i];
            int x = pos.first;
            int y = pos.second;
            if (judge(x+d1,y+d2)) {
                sum += grid_[x+d1][y+d2];
            }
        }
        return sum;
    }

private:
    int n,m;
    map<int, pair<int,int>> mp;
    vector<vector<int>> grid_;
    bool judge(int x, int y) {
        if (x < 0 || x >= n) return false;
        if (y < 0 || y >= m) return false;
        return true;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */