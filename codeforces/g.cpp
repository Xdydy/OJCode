#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int ans[maxn];
int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) {
        int n ; cin >> n;
        int cur = 0;
        for ( int i = 1 ; i <= n-2 ; i++ ) {
            ans[i] = i;
            cur ^= i;
        }
        if ( cur ) {
            ans[n-1] = cur | (1<<29);
            ans[n] = 1<<29;
        }
        else {
            ans[n-2] |= (1<<28);
            ans[n-1] = 1 << 29;
            ans[n] = (1<<29) | (1<<28);
        }

        int o = 0 , e = 0;

        for ( int i = 1 ; i <= n ; i++ ) {
            if ( i % 2 ) {
                o ^= ans[i];
            }
            else {
                e ^= ans[i];
            }
            cout << ans[i] << " ";
        }
        cout << endl;

        // cout << o << " " << e << endl;
    }

}