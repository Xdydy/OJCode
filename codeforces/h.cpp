#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
ll ans[maxn];

int c[maxn];
int lowbit(int x) {
    return x & -x;
}
void add(int x, int v) {
    while(x <= n+2 ) {
        c[x] += v;
        x += lowbit(x);
    }
}
int qry(int x) {
    int ret = 0 ;
    while(x) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}

int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i], a[i]++;
        memset(c, 0, sizeof(int)*(n+5));

        ll res = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            res += (i-1-qry(a[i]-1));
            add(a[i],1);
        }
        ans[cas] = res;

    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}