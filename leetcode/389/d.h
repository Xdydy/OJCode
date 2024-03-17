#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

ll pre[maxn];
class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        ll res = 1ll<<60;
        int n = nums.size();
        vector<int> v;
        for ( int i = 0 ; i < n ; i++) {
            if (nums[i] == 1) {
                v.push_back(i);
            }
        }
        int sz = v.size();
        for (int i =0; i < sz; i++) {
            int r = i + k - maxChanges - 1;
            int mid = i+r >> 1;
            int pos = v[mid];

        }
    }
};