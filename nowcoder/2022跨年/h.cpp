#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[805][805];

ll ans = 0;


int main ()  {
    cin >> n ;
    int minx = 1 << 29;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            cin >> a[i][j];
            ans += a[i][j];
        }
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            if ( (i+j) & 1 ) {
                minx = min(minx, a[i][j]);
            }
        }
    }
    if ( n % 2 ) {
        cout << ans << endl;
    } else {
        cout << ans-minx << endl;
    }
}