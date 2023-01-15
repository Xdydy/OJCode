#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n = nums.size();
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            int x = nums[i];
            for ( int j = 0 ; j <= 30 ; j++ ) {
                a[i+1][j] = ((1<<j) & x);
            }
        }
        int ans = 0;
        for ( int i = 0 ; i <= 30 ; i++ ) {
            int flag = 0;
            int cnt1 = 0 ;
            for ( int j = 1 ; j <= n ; j++ ) {
                if ( a[j][i] ) {
                    cnt1++;
                }
            }
            int cnt0 = n-cnt1;
            ll tmp = 1ll*cnt1*(1ll*n*n-1ll*cnt0*cnt0);
            flag = tmp % 2;
            ans |= (flag<<i);
        }
        return ans;
    }
private:
    int a[maxn][35];
};