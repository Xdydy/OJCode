#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        auto judge = [=](int x){
            int cnt = 0 ;
            for ( int i = 0 ; i < nums.size() ; i++ ) {
                if ( nums[i] <= x ) {
                    cnt++;
                    i++;
                }
            }
            return cnt >= k;
        };
        int left = 1 , right = 1e9+1;
        while(left < right) {
            int mid = left + right >> 1;
            if (judge(mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};