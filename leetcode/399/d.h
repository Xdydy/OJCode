#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int a[maxn];
struct Node {
    int l,r;
    int has_left;
    int has_right;
    int both_has;
    int none_has;
}nodes[maxn];

void pushup(int x) {
    int len = nodes[x].r - nodes[x].l + 1;
    int has_left = 0;
    if (len == 2) {
        has_left = max(0,nodes[x<<1].both_has);
    } else {
       has_left = max(has_left, nodes[x<<1].has_left+nodes[x<<1|1].has_left);
       has_left = max(has_left, nodes[x<<1].both_has+nodes[x<<1|1].none_has);
    }
    int has_right = 0;
    if (len == 2) {
        has_right = max(0,nodes[x<<1|1].both_has);
    } else {
        has_right = max(has_right, nodes[x<<1].has_right+nodes[x<<1|1].has_right);
        has_right = max(has_right, nodes[x<<1].none_has+nodes[x<<1|1].both_has);
    }
    int none_has = 0;
    none_has = max(none_has, nodes[x<<1].has_right + nodes[x<<1|1].none_has);
    none_has = max(none_has, nodes[x<<1].none_has + nodes[x<<1|1].has_left);
    none_has = max(none_has, nodes[x<<1].none_has + nodes[x<<1|1].none_has);
    int both_has = 0;
    both_has = max(both_has, nodes[x<<1].has_left+nodes[x<<1|1].has_right);
    both_has = max(both_has, nodes[x<<1].both_has+nodes[x<<1|1].has_right);
    both_has = max(both_has, nodes[x<<1].has_left+nodes[x<<1|1].both_has);
    nodes[x].has_left = has_left;
    nodes[x].has_right = has_right;
    nodes[x].both_has = both_has;
    nodes[x].none_has = none_has;
    return;
}

void build(int x, int l, int r) {
    nodes[x].l = l, nodes[x].r = r;
    if (l == r) {
        nodes[x].has_left = nodes[x].has_right = nodes[x].none_has = 0;
        nodes[x].both_has = max(0,a[l]);
        return;
    }
    int mid = l + r >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void upd(int x, int pos, int val) {
    if (nodes[x].l == nodes[x].r && nodes[x].l == pos) {
        nodes[x].both_has = max(0,val);
        return;
    }
    int mid = nodes[x].l + nodes[x].r >> 1;
    if (pos <= mid) {
        upd(x<<1,pos,val);
    } else  {
        upd(x<<1|1,pos,val);
    }
    pushup(x);
}

class Solution {
private:
    const ll mod = 1e9+7;
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            a[i] = nums[i-1];
        }
        build(1,1,n);
        ll ans = 0;
        for (auto query: queries) {
            int pos = query[0]+1;
            int x = query[1];
            upd(1,pos,x);
            int res = 0;
            res = max(res, nodes[1].has_left);
            res = max(res, nodes[1].has_right);
            res = max(res, nodes[1].none_has);
            res = max(res, nodes[1].both_has);
            ans += res;
            ans %= mod;
        }
        return ans;
    }
};
