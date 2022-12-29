#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[5005];
ll ans[maxn];

int c[5005];
int lowbit(int x) {
    return x & -x;
}
void add(int x, int v) {
    while(x <= n) {
        c[x] += v;
        x += lowbit(x);
    }
}
int qry(int x ) {
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
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        memset(c, 0, sizeof(int)*(n+3));

        ll res = 0 ;
        add(a[1], 1);
        for ( int i = 2 ; i <= n ; i++ ) {
            ll tmp = 0 ;
            for ( int j = i+1 ; j <= n ; j++ ) {
                if ( a[i] > a[j] ) {
                    res += tmp;
                }
                tmp += qry(a[j]);
            }
            add(a[i],1);
        }
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}