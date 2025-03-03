#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool first_line = false;
        bool first_col = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        first_line = 1;
                    }
                    if (j == 0) {
                        first_col = 1;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_line) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        if (first_col) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }

    }
};