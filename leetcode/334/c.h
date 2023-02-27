#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        auto judge = [=](int x) {
            vector<int> tmp;
            for ( int i = 0 ; i < x ; i++ ) {
                tmp.push_back(2*nums[i]);
            }
            int pos = 0 ;
            for ( int i = x ; i < nums.size(); i++ ) {
                if ( pos == tmp.size() ) break;
                if ( nums[i] >= tmp[pos] ) {
                    pos++;
                } else {
                    continue;
                }
            }
            return pos == tmp.size();
        };

        int left = -1, right = n/2;
        while(left < right) {
            int mid = left + right + 1 >> 1;
            if (judge(mid)) {
                left = mid;
            } else {
                right = mid-1;
            }
        }
        return left*2;
    }
};