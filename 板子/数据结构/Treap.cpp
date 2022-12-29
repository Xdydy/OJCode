#include <bits/stdc++.h>
using namespace std;
#define maxn (int)(3e6 + 10)
#define LL long long
#define IOS ios::sync_with_stdio(0)

inline int qread()
{
    char c;
    int s = 0, t = 1;
    while ((c = getchar()) < '0' || c > '9')
        (c == '-' && (t = -1));
    do
        s = s * 10 + c - '0';
    while ((c = getchar()) >= '0' && c <= '9');
    return s * t;
}

int l[maxn], r[maxn], val[maxn], rnd[maxn], siz[maxn], w[maxn];
int sz, rt;
LL ans;
void pushup(int x) { siz[x] = siz[l[x]] + siz[r[x]] + w[x]; }
void lrotate(int &k)
{
    int t = r[k];
    r[k] = l[t];
    l[t] = k;
    siz[t] = siz[k];
    pushup(k);
    k = t;
}

void rrotate(int &k)
{
    int t = l[k];
    l[k] = r[t];
    r[t] = k;
    siz[t] = siz[k];
    pushup(k);
    k = t;
}

void insert(int &k, LL x)
{
    if (!k)
    {
        sz++;
        k = sz;
        siz[k] = 1;
        w[k] = 1;
        val[k] = x;
        rnd[k] = rand();
        return;
    }
    siz[k]++;
    if (val[k] == x)
    {
        w[k]++;
    }
    else if (val[k] < x)
    {
        insert(r[k], x);
        if (rnd[r[k]] < rnd[k])
            lrotate(k);
    }
    else
    {
        insert(l[k], x);
        if (rnd[l[k]] < rnd[k])
            rrotate(k);
    }
}

bool del(int &k, LL x)
{
    if (!k)
        return false;
    if (val[k] == x)
    {
        if (w[k] > 1)
        {
            w[k]--;
            siz[k]--;
            return true;
        }
        if (l[k] == 0 || r[k] == 0)
        {
            k = l[k] + r[k];
            return true;
        }
        else if (rnd[l[k]] < rnd[r[k]])
        {
            rrotate(k);
            return del(k, x);
        }
        else
        {
            lrotate(k);
            return del(k, x);
        }
    }
    else if (val[k] < x)
    {
        bool succ = del(r[k], x);
        if (succ)
            siz[k]--;
        return succ;
    }
    else
    {
        bool succ = del(l[k], x);
        if (succ)
            siz[k]--;
        return succ;
    }
}

int queryrank(int k, LL x)
{
    if (!k)
        return 0;
    if (val[k] == x)
        return siz[l[k]];
    else if (x > val[k])
    {
        return siz[l[k]] + w[k] + queryrank(r[k], x);
    }
    else
        return queryrank(l[k], x);
}
int querynum(int k, LL x)
{
    if (!k)
        return 0;
    if (x <= siz[l[k]])
        return querynum(l[k], x);
    else if (x > siz[l[k]] + w[k])
        return querynum(r[k], x - siz[l[k]] - w[k]);
    else
        return val[k];
}


void querysub(int k, LL x)
{
    if (!k)
        return;
    if (val[k] > x)
        ans = k, querysub(l[k], x);
    else
        querysub(r[k], x);
}

int main()
{
    freopen("input.txt","r",stdin);
    srand(0);
    int n = qread();
    for (int i = 1; i <= n; i++)
    {
        int op;
        op = qread();
        LL x;
        x = qread();
        if (op == 1)
            insert(rt, x);
        else if (op == 2)
            del(rt, x);
        else if (op == 3)
            printf("%d\n", queryrank(rt, x));
        else if (op == 4)
            printf("%d\n", querynum(rt, x));
        else if (op == 5)
        {
            ans = 0;
            querysub(rt, x);
            printf("%d\n", val[ans]);
        }
    }
}