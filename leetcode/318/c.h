#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    long long totalCost(vector<int> &costs, int k, int candidates) {
        set<pair<int, int>> st;
        int left, right;
        left = candidates - 1;
        right = costs.size() - candidates;
        for (int i = 0; i <= left; i++) {
            st.insert({costs[i], i});
        }
        for (int i = right; i < costs.size(); i++) {
            st.insert({costs[i], i});
        }
        ll res = 0;
        while(k--) {
            auto top = *st.begin();
            res += top.first;
            st.erase(st.begin());
            if ( left < right ) {
                if ( top.second <= left ) {
                    left++;
                    st.insert({costs[left], left});
                }
                else if ( top.second >= right ) {
                    right--;
                    st.insert({costs[right], right});
                }
            }
        }
        return res;
    }
};