#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n = matrix.size();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            if (pos < matrix[i].size() && matrix[i][pos] == target) {
                flag = true;
                break;
            }
        }
        return flag;
    }
};