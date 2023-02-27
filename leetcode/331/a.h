#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for ( auto x : gifts ) {
            pq.push(x);
        }
        while(k--) {
            auto top = pq.top();
            pq.pop();
            top = sqrt(top);
            pq.push(top);
        }
        ll ans = 0 ;
        while(pq.size()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};