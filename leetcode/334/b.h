#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        ll rest = 0;
        for (char ch : word) {
            rest = rest * 10 + ch - '0';
            rest %= m;
            if (rest == 0) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        
        }
        return ans;
    }
};