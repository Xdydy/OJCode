#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0 ;
        int d = 0 ;
        for ( auto x : nums ) {
            sum += x;
            while(x) {
                d += x%10;
                x /= 10;
            }
        }      
        return abs(sum-d);
    }
};