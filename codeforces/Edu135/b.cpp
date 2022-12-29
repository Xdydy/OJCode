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
        if ( n % 2 == 0 ) {
            ans[n] = n;
            ans[n-1] = n-1;
            int cur = 1 ;
            for ( int i  = n-2 ; i >= 1 ; i-- ) {
                ans[i] = cur++;
            }
        }
        else {
            ans[n] = n ;
            ans[n-1] = n-1;
            ans[1] = 1 , ans[2] = 2 , ans[3] = 3;
            int cur = 4;
            for ( int i = n-2 ; i >= 4; i-- ) {
                ans[i] = cur++;
            }
        }
        for ( int i = 1 ; i <= n ; i++ ) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}