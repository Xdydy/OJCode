#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    int solve(vector<int> v /*{1, -1, 0, 0}*/, int k) {
        int n = v.size();
        int prex = 0, prey = 0;
        int curx = 0, cury = 0;
        int minx[2][2];
        minx[0][0] = minx[0][1] = minx[1][0] = minx[1][1] = 1 << 29;
        int left = 1;
        int ans = -(1<<29);
        for (int i = 1; i <= n; i++) {
            int x = v[i-1];
            if (x == 1) {
                curx++;
            } else if (x == -1) {
                cury++;
            }

            int right = i;
            while(right - left + 1 >= k && curx > prex && cury > prey) {
                int p = prex & 1;
                int q = prey & 1;
                minx[p][q] = min(minx[p][q], prex-prey);
                x = v[left-1];
                if (x == 1) {
                    prex++;
                } else if (x == -1) {
                    prey++;
                }
                left++;
            }
            if (right >= k) {
                ans = max(ans, curx-cury - minx[curx&1^1][cury&1]);
            }

        }
        return ans;
        
    }
public:
    int maxDifference(string s, int k) {
        int ans = -(1<<29) ;
        for (int i = 0; i <= 4; i++) {
            for (int j = 0; j <= 4; j++) {
                if (i == j) continue;
                int n = s.length();
                vector<int> v;
                for (int k = 0; k < n; k++) {
                    int ch = s[k] - '0';
                    if (ch == i) {
                        v.push_back(1);
                    } else if (ch == j) {
                        v.push_back(-1);
                    } else {
                        v.push_back(0);
                    }
                }
                ans = max(ans, solve(v,k));
            }
        }
        return ans;
    }
};