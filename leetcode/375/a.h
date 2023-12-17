#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int countTestedDevices(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for ( int i = 0 ; i < n ; i++ ) {
            if (a[i] > 0) {
                ans++;
                for ( int j = i+1 ; j < n ; j++ ) {
                    a[j] = max(0,a[j]-1);
                }
            }
        }
        return ans;
    }
};