#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
ll a[maxn];
ll ans[maxn];
void solve() {
    cin >>n;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    int maxx1 = 0;
    int maxx2 = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if (a[i] >= maxx1) {
            maxx2 = maxx1;
            maxx1 = a[i];
        } else if ( a[i] > maxx2 ) {
            maxx2 = a[i];
        }
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( a[i] != maxx1 ) {
            ans[i] = a[i] - maxx1;
        } else {
            ans[i] = a[i] - maxx2;
        }
    }
    for ( int i =1  ; i <= n ; i++ ) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main () {
    IOS;
    int T ; cin >> T;
    while(T--) {
        solve();
    }
}