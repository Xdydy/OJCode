#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int a[maxn];
struct Node {
    int l , r;
    int maxx;
}nodes[maxn];

void pushup(int x) {
    nodes[x].maxx = max(nodes[x<<1].maxx, nodes[x<<1|1].maxx);
}

void build(int x, int l, int r) {
    nodes[x].l = l;
    nodes[x].r = r;
    if (l == r) {
        nodes[x].maxx = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(x<<1, l, mid);
    build(x<<1|1, mid+1, r);
    pushup(x);
}

int qry(int x, int val) {
    if (nodes[x].l == nodes[x].r) {
        if (nodes[x].maxx < val) {
            return -1;
        } else {
            return nodes[x].l;
        }
    }
    if (nodes[x].maxx < val) {
        return -1;
    }
    int mid = nodes[x].l + nodes[x].r >> 1;
    int res = qry(x<<1, val);
    if (res != -1) {
        return res;
    } else {
        return qry(x<<1|1, val);
    }
}

void upd(int x, int pos) {
    if (nodes[x].l == nodes[x].r) {
        nodes[x].maxx = 0;
        return;
    }
    int mid = nodes[x].l + nodes[x].r >> 1;
    if (pos <= mid) {
        upd(x<<1, pos);
    } else {
        upd(x<<1|1, pos);
    }
    pushup(x);
}


class Solution {
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
        int n = baskets.size();
        vector<int> v;
        for (auto x: fruits) {
            v.push_back(x);
        }
        for (auto x: baskets) {
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        unique(v.begin(), v.end());
        for (int i = 1; i <= n; i++) {
            a[i] = baskets[i-1];
            // a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        }
        build(1,1,n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = fruits[i];
            // x = lower_bound(v.begin(), v.end(), x) - v.begin();
            int res = qry(1,x);
            if (res == -1) {
                ans++;
            } else {
                upd(1,res);
            }
        }
        return ans;
    }
};