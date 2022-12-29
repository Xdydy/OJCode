#include <bits/stdc++.h>
using namespace std;
#define maxn (int)(1e5+10)
#define LL long long
#define IOS ios::sync_with_stdio(0)

int lazy[maxn<<3];
int s[maxn << 3];

struct node1 {
    int l, r;
    int sum;
}cl[maxn<< 3];

struct node2 {
    int x, y1, y2;
    int flag ;
}p[maxn<<3];

void pushup(int rt) {
    if (lazy[rt] > 0)
        cl[rt].sum = cl[rt].r - cl[rt].l;
    else 
        cl[rt].sum = cl[rt<<1].sum + cl[rt<<1|1].sum;
}

void build(int rt, int l, int r) {
    if ( r - l > 1 ) {
        cl[rt].l = s[l];
        cl[rt].r = s[r];
        build(rt<<1, l, (l+r) >> 1);
        build(rt<<1|1, (l+r) >> 1, r);
        pushup(rt);
    }
    else  {
        cl[rt].l = s[l];
        cl[rt].r = s[r];
        cl[rt].sum = 0;
    }
    return ;
}
void update(int rt, int y1, int y2, int flag) {
    if (cl[rt].l == y1 && cl[rt].r == y2 ) {
        lazy[rt] += flag ;
        pushup(rt);
        return ;
    }
    else {
        if (cl[rt<<1].r > y1) update(rt<<1, y1, min(cl[rt<<1].r, y2),flag );
        if (cl[rt<<1|1].l < y2)
            update(rt<<1|1, max(cl[rt<<1|1].l, y1), y2, flag );
        pushup(rt);
    }
}
int n;

int main ()
{
    IOS;
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ )
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if ( x1 > x2 ) swap(x1,x2);
        if ( y1 > y2 ) swap(y1,y2);
        p[i].x = x1;
        p[i].y1 = y1;
        p[i].y2 = y2;
        p[i].flag = 1;
        p[i+n].x = x2;
        p[i+n].y1 = y1;
        p[i+n].y2 = y2;
        p[i+n].flag = -1;
        s[i+1] = y1;
        s[i+n+1] = y2;
    }
    sort(s+1, s+(2*n+1));
    sort(p, p+2*n, [](node2 a, node2 b)->bool{
        return a.x < b.x;
    });
    build(1,1,2*n);
    memset(lazy, 0, sizeof(lazy));
    update(1, p[0].y1, p[0].y2, p[0].flag);
    LL ans = 0 ;
    for ( int i = 1 ; i < 2*n ; i++ )
    {
        ans += (p[i].x - p[i-1].x) * cl[1].sum;
        update(1, p[i].y1, p[i].y2, p[i].flag);
    }
    cout << ans << endl;
}