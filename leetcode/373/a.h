#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size() ;
        int m = mat[0].size();
        bool flag = true;
        for ( int i = 0 ; i < n ; i++ ) {
            int index = i+1;
            if (index & 1) {
                cout << i << endl;
                for ( int j = 0 ; j < m ; j++ ) {
                    if (mat[i][j] != mat[i][(j+k%m)%m]) {
                        flag = false;
                        break;
                    }
                }
            } else {
                cout << i << endl;
                for ( int j = 0 ; j < m ; j++ ) {
                    cout << "j: " << j << endl;
                    if (mat[i][j] != mat[i][(j+m-k%m)%m]) {
                        flag = false;
                        break;
                    }
                }
                
            }
            if (!flag) {
                break;
            }
        }
        return flag;
    }
};