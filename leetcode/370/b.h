#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    int deg[105];
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        memset(deg,0,sizeof(deg));
        for ( auto edge : edges ) {
            int u = edge[0];
            int v = edge[1];
            deg[v]++;
        }
        vector<int> ans;
        for ( int i = 0 ; i < n ; i++ ) {
            if (!deg[i]) {
                ans.push_back(i);
            }
        }
        if (ans.size()==1) {
            return ans.front();
        } else {
            return -1;
        }
    }
};