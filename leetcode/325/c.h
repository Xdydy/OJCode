#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());       
        int l = 0 , r = price.back()-price.front();

        auto judge = [=](int x) -> bool {
            int cnt = 1;
            int cur = 0;
            while(cnt < k && cur < n) {
                int pos = lower_bound(price.begin(),price.end(),price[cur]+x) - price.begin();
                if ( pos < n ) {
                    cur = pos;
                    cnt++;
                } else {
                    break;
                }
            }
            return cnt >= k;
        };
        while(l < r){
            int mid = l + r + 1 >> 1;
            if ( judge(mid) ) {
                l = mid ;
            } else {
                r = mid-1;
            }
        }
        return l;
    }

};