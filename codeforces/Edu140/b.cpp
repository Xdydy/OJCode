#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
ll a[maxn];
ll ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        sort(a+2,a+1+n);
        int cur = 2;
        ll res = a[1];
        while(cur <= n) {
            if ( res >= a[cur] ) {
            }
            else {
                res = (a[cur] + res + 1) / 2;
            }
            cur++;
        }
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}