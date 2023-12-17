#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    int quick_pow(int x, int k, int mod) {
        int res = 1;
        while(k) {
            if (k&1) {
                res = res * x % mod;
            }
            k >>= 1;
            x = x * x % mod;
        }
        return res;
    }
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for ( int i = 0 ; i < variables.size() ; i++ ) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];

            int ab = quick_pow(a,b,10) % 10;
            int bc = quick_pow(ab,c,m);
            if (bc == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};