#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int a[maxn];
struct node {
    int l,r;
    ll maxx;
}Node[maxn];

void pushup(int x) {
    Node[x].maxx = max(Node[x<<1].maxx,Node[x<<1|1].maxx);
}


void build(int x, int l, int r) {
    Node[x].l = l;
    Node[x].r = r;
    if (l == r) {
        Node[x].maxx = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

int qry(int x, int l, int r) {
    if (Node[x].l >= l && Node[x].r <= r) {
        return Node[x].maxx;
    }
    int mid = Node[x].l + Node[x].r >> 1;
    if (r <= mid) {
        return qry(x<<1,l,r);
    } else if (l > mid) {
        return qry(x<<1|1,l,r);
    } else {
        return max(qry(x<<1,l,mid), qry(x<<1|1,mid+1,r));
    }
}


class Solution {
private:
    bool check(int l,int r, int val) {
        int res = qry(1,l,r);
        return res > val;
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        for ( int i = 1 ; i <= n ; i++ ) {
            int x = heights[i-1];
            a[i] = x;
        }
        build(1,1,n);
        vector<int> ans;
        for (auto qry : queries) {
            int u = min(qry[0],qry[1]) + 1;
            int v = max(qry[0],qry[1]) + 1;
            if (a[u] < a[v] || u == v) {
                ans.push_back(v-1);
            } else {
                int left = v+1;
                int right = n+1;
                int val = a[u];
                while(left < right) {
                    int mid = left + right >> 1;
                    if (check(v+1,mid,val)) {
                        right = mid;
                    } else {
                        left = mid+1;
                    }
                }
                if (left == n+1) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(left-1);
                }
            }   
        }
        return ans;
    }
};