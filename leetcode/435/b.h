#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    int solve(vector<int> a, int k) {
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == -1) {
                if (k) {
                    k--;
                    cur++;
                } else {
                    cur--;
                }
            } else {
                cur++;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
public:
    int maxDistance(string s, int k) {
        vector<int> dest[4];
        dest[0] = {1,-1,1,-1};
        dest[1] = {-1,1,1,-1};
        dest[2] = {1,-1,-1,1};
        dest[3] = {-1,1,-1,1};
        int ans = 0 ;
        for (int i = 0; i < 4; i++) {
            vector<int> tmp;
            for (auto x : s) {
                if (x == 'N') {
                    tmp.push_back(dest[i][0]);
                } else if (x == 'S') {
                    tmp.push_back(dest[i][1]);
                } else if (x == 'W') {
                    tmp.push_back(dest[i][2]);
                } else {
                    tmp.push_back(dest[i][3]);
                }
            }
            ans = max(ans, solve(tmp,k));
        }
        return ans;
    }
};