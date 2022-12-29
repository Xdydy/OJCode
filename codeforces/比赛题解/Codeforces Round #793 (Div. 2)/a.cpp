#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
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
        string s ;
        cin >> s ;
        s = ' ' + s;
        if ( n & 1 ) {
            int mid = (n+1) / 2;
            int cnt = 0 ;
            for ( int i = mid ; i >= 1 && s[i] == s[mid] ; i-- ) {
                cnt++;
            }
            for ( int i = mid+1 ; i <= n && s[i] == s[mid] ; i++ ) {
                cnt++;
            }
            ans[cas] = cnt;
        }
        else {
            int mid = n / 2;
            int cnt = 0 ;
            for ( int i = mid ; i >= 1 && s[i] == s[mid] ; i-- ) {
                cnt++;
            }
            for ( int i = mid+1 ; i <= n && s[i] == s[mid] ; i++ ) {
                cnt++;
            }
            ans[cas] = cnt;
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}