#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m;
int a[maxn];
int b[maxn];
int ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        cin >> m;
        for ( int i = 1 ; i <= m ; i++ ) cin >> b[i];

        ll sum = 1 ;
        for ( int i = 1; i <= m ; i++ ) sum += b[i];

        int rest = sum % n ;
        if ( rest == 0 ) rest = n ;
        ans[cas] = a[rest];
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}