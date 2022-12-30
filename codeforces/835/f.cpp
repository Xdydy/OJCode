#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,d;
ll c;
ll a[maxn];
ll ans[maxn];
ll sum[maxn];

bool judge(int x) {
    int t = d/x;
    int rest = d % x;
    ll res = sum[min(n,x)]*t;
    res += sum[min(n,rest)];
    return res >= c;
}

int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n >> c >> d;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        sort(a+1,a+1+n,greater<ll>());
        for ( int i = 1 ; i <= n ; i++ ) {
            sum[i] = sum[i-1] + a[i];
        }
        if ( a[1]*d < c ) {
            ans[cas] = -1;
        } else if ( sum[min(d,n)] >= c ) {
            ans[cas] = -2;
        } else {
            int l = 0;
            int r = d+1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if (judge(mid)) {
                    l = mid;
                } else {
                    r = mid-1;
                }
            }
            ans[cas] = l-1;
        }
    }
    for ( int i = 1 ; i <= T ; i++ ) {
        if ( ans[i] == -1 ) {
            cout << "Impossible" << endl;
        } else if ( ans[i] == -2) {
            cout << "Infinity"  << endl;
        } else {
            cout << ans[i] << endl;
        }
    }
}