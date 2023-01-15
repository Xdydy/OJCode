#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        n = stations.size();
        this->r=r;
        this->k=k;
        pre[0] = 0;
        for ( int i = 1 ; i <= n ; i++ ) {
            pre[i] = pre[i-1] + stations[i-1];
        }
        for ( int i = 1 ; i <= n ; i++ ) {
            int st = max(1,i-r);
            int ed = min(n,i+r);
            a[i] = pre[ed] - pre[st-1];
        }

        ll left = 0 ;
        ll right = 1ll<<60;
        while(left<right) {
            ll mid = left + right + 1 >> 1;
            if (judge(mid)) {
                left = mid;
            } else {
                right = mid-1;
            }
        }
        return left;
    }
private:
    int n,r,k;
    ll pre[maxn];
    ll a[maxn];
    bool judge(ll x) {
        vector<pair<ll,int>> v;
        for ( int i = 1 ; i <= n ; i++ ) {
            if (a[i] >= x) continue;
            v.push_back({x-a[i],i});
        }
        ll need = 0 ;
        ll cur = 0 ;
        queue<pair<ll,int>> q;
        for ( auto ss : v ) {
            ll ned = ss.first;
            int pos = ss.second;
            while ( q.size() && q.front().second + 2*r < pos ) {
                auto top = q.front();
                q.pop();
                need += top.first;
                if ( need > k ) 
                    return false;
                cur -= top.first;
            }
            if ( ned > cur ) {
                q.push({ned-cur,pos});
                cur = ned;
            }
        }
        while(q.size()) {
            auto top = q.front();
            need += top.first;
            if ( need > k )
                return false;
            q.pop();
        }
        return need <= k;
    }
};