#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,k;
int ans[maxn];
void solve() {
    cin >> n >> k;
    int l = 1 ; 
    int r = n ;
    for ( int i = 1; i <= n ; i++ ) {
        if ( i&1 ) {
            ans[i] = r--;
        } else {
            ans[i] = l++;
        }
    }
    for ( int i = 1 ; i <= n ; i++ ) {
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