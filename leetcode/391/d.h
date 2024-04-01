#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 



class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> p[4];
        for (auto point: points) {
            int x = point[0];
            int y = point[1];
            p[0].push_back(x+y);
            p[1].push_back(-x+y);
            p[2].push_back(x-y);
            p[3].push_back(-x-y);
        }        
        for (int i = 0 ; i < 4 ; i++ ) {
            sort(p[i].begin(), p[i].end());
        }
        int minx = 1<<30;
        for (auto point: points) {
            int x = point[0];
            int y = point[1];
            int sum;
            int maxx = 0;
            for (int i = 0; i < 4; i++) {
                if (i==0) {
                    sum = x+y;
                } else if (i==1) {
                    sum = -x+y;
                } else if (i==2) {
                    sum = x-y;
                } else if (i==3) {
                    sum = -x-y;
                }
                int pos = lower_bound(p[i].begin(), p[i].end(), sum) - p[i].begin();
                if (pos == n-1) {
                    maxx = max(maxx, p[i][n-2]-p[i][0]);
                } else if (pos == 0) {
                    maxx = max(maxx, p[i][n-1]-p[i][1]);
                } else {
                    maxx = max(maxx, p[i][n-1]-p[i][0]);
                }
            }
            minx = min(minx, maxx);
        }
        return minx;
    }
};