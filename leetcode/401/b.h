#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    const ll mod = 1e9+7;
    ll a[1005];
    ll pre[1005];
public:
    int valueAfterKSeconds(int n, int k) {
        for (int i = 0; i < n; i++) {
            a[i] = 1;
        }
        pre[0] = a[0];
        for (int i = 1;i < n; i++) {
            pre[i] = (pre[i-1] + a[i]) % mod;
        }
        while(k--) {
            for (int i = 1; i < n; i++) {
                a[i] = (pre[i-1] + a[i]) % mod;
            }
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i-1] + a[i];
                pre[i] %= mod;
            }
        }
        return a[n-1];
    }
};