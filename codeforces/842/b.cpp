#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,k;
int a[maxn];
int ans[maxn];


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n >> k;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        int cur = 1;
        int cnt = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( a[i] == cur ) {
                cur++;
            } else {
                cnt++;
            }
        }
        int res = cnt / k;
        if (cnt%k) res++;
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}

