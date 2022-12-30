#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
ll ans[maxn];
int cnt0[maxn],cnt1[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        for ( int i = 1 ; i <= n ; i++ ) {
            cnt0[i] = cnt0[i-1];
            cnt1[i] = cnt1[i-1];
            if ( a[i] == 1 ) {
                cnt1[i]++;
            } else {
                cnt0[i]++;
            }
        }
        int maxx = 0 ;
        int pos = 0;
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( a[i] == 1 ) {
                int p = cnt1[i-1];
                int m = cnt0[n]-cnt0[i];
                if ( p-m > maxx ) {
                    maxx = p-m;
                    pos = i;
                }
            } else {
                int m = cnt1[i-1];
                int p = cnt0[n]-cnt0[i];
                if ( p-m > maxx ) {
                    maxx = p-m;
                    pos = i;
                }
            }
        }
        a[pos] ^= 1;
        ll res = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            cnt0[i] = cnt0[i-1];
            cnt1[i] = cnt1[i-1];
            if ( a[i] == 1 ) {
                cnt1[i]++;
            } else {
                cnt0[i]++;
            }
        }
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( a[i] ) {
                res += cnt0[n]-cnt0[i];
            }
        }
        ans[cas] = res;

    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}