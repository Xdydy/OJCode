#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(5e4+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        set<int> st;
        st.insert(0);
        for(auto x : rewardValues) {
            for (auto y: st) {
                if (y < x) {
                    st.insert(y+x);
                } else {
                    break;
                }
            }
        }
        return *st.rbegin();
    }
};