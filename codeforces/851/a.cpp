#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
int ans[maxn];


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        int cnt = 0;
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( a[i] == 2 ) {
                cnt++;
            }
        }
        if ( !cnt ) {
            ans[cas] = 1;
        }
        else if ( cnt % 2 ==0  ) {
            int cnt2 = 0 ;
            int res = -1;
            for ( int i = 1 ; i <= n ; i++ ) {
                if ( a[i] == 2 ) {
                    cnt2++;
                }
                if ( cnt2 * 2 == cnt ) {
                    res = i;
                    break;
                }
            }
            ans[cas] = res;
        }
        else {
            ans[cas] = -1;
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}