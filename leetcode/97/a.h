#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for ( auto x : nums ) {
            vector<int> tmp;
            while(x) {
                tmp.push_back(x%10);
                x /= 10;
            }
            reverse(tmp.begin(),tmp.end());
            for ( auto y : tmp ) {
                ans.push_back(y);
            }
        }
        return ans;
    }
};