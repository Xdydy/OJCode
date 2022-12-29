#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int n;
int a[maxn];
int ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        int l = 0 , r = 1e8;
        for ( int i = 1 ; i < n ; i++ ) {
            if ( a[i] < a[i+1] ) {
                int mid = a[i] + a[i+1] >> 1;
                r = min(r,mid);
            } else if ( a[i] > a[i+1] ) {
                int mid = a[i] + a[i+1] + 1 >> 1;
                l = max(l,mid);
            }
            if ( l > r ) {
                break;
            }
        }
        if ( l > r ) {
            ans[cas] = -1;
        } else {
            ans[cas] = l;
        }
        // for ( int i = 1 ; i <= n ; i++ ) {
        //     cout << abs(a[i]-l) << " ";
        // }
        // cout << endl;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}