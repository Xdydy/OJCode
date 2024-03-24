#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
struct Node {
    int l, r;
    ll maxx = 0;
}nodes[maxn];

void pushup(int x) {
    nodes[x].maxx = max(nodes[x<<1].maxx, nodes[x<<1|1].maxx);
}

void build(int x, int l, int r) {
    nodes[x].l = l, nodes[x].r = r;
    if (l == r) {
        nodes[x].maxx = 0;
        return ;
    }
    int mid = l + r >> 1;
    build(x<<1, l, mid);
    build(x<<1|1, mid+1,r);
    pushup(x);
}

void upd(int x, int pos, ll d) {
    if (nodes[x].l == nodes[x].r) {
        nodes[x].maxx += d;
        return;
    }
    int mid = nodes[x].l + nodes[x].r >> 1;
    if (pos <= mid) {
        upd(x<<1, pos, d);
    } else {
        upd(x<<1|1, pos, d);
    }
    pushup(x);
}

ll qry(int x, int l, int r) {
    if (nodes[x].l >= l && nodes[x].r <= r) {
        return nodes[x].maxx;
    }
    int mid = nodes[x].l + nodes[x].r >> 1;
    if (r <= mid) {
        return qry(x<<1, l, r);
    } else if (l > mid) {
        return qry(x<<1, l, r);
    } else {
        return max(qry(x<<1, l, mid), qry(x<<1|1, mid+1, r));
    }
}


class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        n = nums.size();
        int maxx = 0;
        for (auto x : nums) {
            maxx = max(maxx, x);
        }
        build(1,1,maxx);
        vector<ll> ans;
        for (int i = 0; i < n; i++) {
            int id = nums[i];
            ll d = freq[i];
            upd(1,id,d);
            ans.push_back(qry(1,1,maxx));
        }
        return ans;
    }
};