#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(5e4 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);


int c[maxn];
int lowbit(int x) {
    return x & (-x);
}
void add(int x, int v) {
    while(x < maxn) {
        c[x] += v;
        x += lowbit(x);
    }
}
int qry(int x) {
    int res = 0 ;
    while(x) {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
class Solution {
public:
    int reversePairs(vector<int> &record) {
        int ans = 0;
        int n = record.size();
        vector<ll> v;
        v.push_back(-(1ll<<60));
        for (auto r : record) {
            v.push_back(r);
        }
        sort(v.begin(), v.end());
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++) {
            int x = record[i-1];
            x = lower_bound(v.begin(), v.end(), x) - v.begin();
            ans += i-1-qry(x);
            add(x, 1);
        }
        return ans;
    }
};