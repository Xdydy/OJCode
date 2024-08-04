#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

struct Node  {
    int l, r;
    int val;
    int lazy;
}nodes[maxn << 3];

void merge(int x) {
    nodes[x].val = nodes[x<<1].val + nodes[x<<1|1].val;
}

void pushdown(int x) {
    nodes[x<<1].lazy = 1, nodes[x<<1|1].lazy = 1;
    nodes[x<<1].val = 0, nodes[x<<1|1].val = 0;
}

void build(int x, int l, int r) {
    nodes[x].l = l, nodes[x].r = r;
    if (l == r) {
        nodes[x].val = 1;
        return;
    }
    int mid = l + r >> 1;
    build(x<<1, l, mid);
    build(x<<1|1, mid+1,r);
    merge(x);
}

void upd(int x, int l, int r) {
    if (nodes[x].l >= l && nodes[x].r <= r) {
        nodes[x].lazy = 1;
        nodes[x].val = 0;
        return;
    }
    if (nodes[x].lazy) {
        pushdown(x);
    }
    int mid = nodes[x].l + nodes[x].r >> 1;
    if (r <= mid) {
        upd(x<<1,l,r);
    } else if (l > mid) {
        upd(x<<1|1,l,r);
    } else {
        upd(x<<1, l, mid);
        upd(x<<1|1, mid+1, r);
    }
    merge(x);
}



class Solution {

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        build(1,1,n);
        vector<int> ans;
        for (auto q : queries) {
            int u = q[0] + 1;
            int v = q[1] + 1;
            upd(1,u+1,v-1);
            int res = nodes[1].val;
            ans.push_back(res-1);
            
        }
        return ans;
    }
};