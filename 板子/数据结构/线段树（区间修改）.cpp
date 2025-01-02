#include <bits/stdc++.h>
using namespace std;
#define maxn (int)(1e5+10)
#define ll long long 

ll a[maxn];
struct Node {
    int left,right;
    ll sum, maxx, minx;
    int lazy;
}nodes[maxn];

void pushup(int x) {
    nodes[x].sum = nodes[x<<1].sum + nodes[x<<1|1].sum;
    nodes[x].maxx = max(nodes[x<<1].maxx, nodes[x<<1|1].maxx);
    nodes[x].minx = min(nodes[x<<1].minx, nodes[x<<1|1].minx);
    return;
}

void pushdown(int x) {
    if (nodes[x].lazy) {
        nodes[x<<1].lazy += nodes[x].lazy;
        nodes[x<<1|1].lazy += nodes[x].lazy;
        nodes[x].lazy = 0;
    }
}

void build(int x, int l, int r) {
    nodes[x].left = l, nodes[x].right = r;
    if (l == r) {
        nodes[x].sum = nodes[x].maxx = nodes[x].minx = a[x];
        nodes[x].lazy = 0;
        return;
    }
    int mid = l + r >> 1;
    build(x<<1, l, mid);
    build(x<<1|1, mid+1, r);
    pushup(x);
}

void update(int x, int l, int r, int d) {
    if (nodes[x].left >= l && nodes[x].right <= r) {
        nodes[x].sum += d * (nodes[x].right - nodes[x].left + 1);
        nodes[x].maxx += d;
        nodes[x].minx += d;
        nodes[x].lazy += d;
        return;
    }
    pushdown(x);
    int mid = nodes[x].left + nodes[x].right >> 1;
    if (l > mid) update(x<<1|1, l, r, d);
    else if (r <= mid) update(x<<1, l, r, d);
    else {
        update(x<<1, l, mid, d);
        update(x<<1|1, mid+1, r, d);
    }
    pushup(x);
}

ll qry(int x, int l, int r) {
    if (nodes[x].left >= l && nodes[x].right <= r) {
        return nodes[x].sum;
    }
    pushdown(x);
    int mid = nodes[x].left + nodes[x].right >> 1;
    if (l > mid) return qry(x<<1|1, l, r);
    else if (r <= mid) return qry(x<<1, l, r);
    else return qry(x<<1, l, mid) + qry(x<<1|1, mid+1, r);
}