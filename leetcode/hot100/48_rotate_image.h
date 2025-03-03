#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
private:
    void rotate_num(int &a, int &b, int &c, int &d) {
        int tmp = d;
        d = c;
        c = b;
        b = a;
        a = tmp;
    }
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; i++) {
            int len = n-i;
            for (int j = i; j < n-i-1; j++) {
                int ar = i, ac = j;
                int br = j, bc = n-i-1;
                int cr = n-i-1, cc = n-j-1;
                int dr = n-j-1, dc = i;
                // cout << ar << " " << ac << "\n";
                // cout << br << " " << bc << "\n";
                // cout << cr << " " << cc << "\n";
                // cout << dr << " " << dc << "\n";
                // cout << "\n";
                rotate_num(matrix[ar][ac], matrix[br][bc], matrix[cr][cc], matrix[dr][dc]);
            }
        }
    }
};