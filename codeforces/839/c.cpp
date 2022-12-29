#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int k,n;
int a[45];
void solve() {
    cin >> k >> n;
    for ( int i = k ; i >= 1 ; i-- ) {
        int d = k-i;
        a[i] = n-d;
    }
    a[1] = 1;
    int d = 1;
    for ( int i = 2 ; i <= k ; i++,d++ ) {
        if ( a[i-1] + d <= a[i] ) {
            a[i] = a[i-1] + d;
        } else {
            break;
        }
    }
    for ( int i = 1 ; i <= k ; i++ ) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main ( ) {
    IOS;
    int T ; cin >> T;
    while(T--) {
        solve();
    }
}