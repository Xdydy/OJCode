#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        for ( int i = 0 ; i < n ; i++ ) {
            vector<int> tmp;
            for ( int j = 0 ; j < n ; j++ ) {
                tmp.push_back(0);
            }
            ans.push_back(tmp);
        }
        for ( auto qry: queries) {
            int row1 = qry[0];
            int col1 = qry[1];
            int row2 = qry[2];
            int col2 = qry[3];
            for ( int i = row1 ; i <= row2 ; i++ ) {
                ans[i][col1]++;
                if ( col2+1 < n ) {
                    ans[i][col2+1]--;
                }
            }
        }
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( j > 0 ) {
                    ans[i][j] += ans[i][j-1];
                }
            }
        }
        return ans;
    }
};