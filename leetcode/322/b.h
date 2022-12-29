#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);


class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        multiset<int> st;
        ll sum = 0;
        for ( auto x : skill ) {
            st.insert(x);
            sum += x;
        }
        ll ans = 0;
        if ( sum % (n/2) ) {
            return -1;
        }
        sum /= (n/2);
        bool flag = 1;
        while(st.size()) {
            ll r1 = *st.begin();
            st.erase(st.begin());
            auto it = st.find(sum-r1);
            if ( it == st.end() ) {
                flag = 0;
                break;
            }
            ll r2 = *it;
            st.erase(it);
            ans += r1*r2;
        }
        if ( flag ) {
            return ans;
        }
        else {
            return -1;
        }
    }
};