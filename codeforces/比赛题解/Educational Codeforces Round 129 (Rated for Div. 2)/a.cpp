#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m;
int a[maxn];
int b[maxn];
int ans1[maxn], ans2[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n ;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        cin >> m;
        for ( int i = 1 ; i <= m ; i++ ) cin >> b[i];
        int max1 = 0 , max2 = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            max1 = max(max1, a[i]);
        }

        for ( int i = 1 ; i <= m ; i++ ) {
            max2 = max(max2, b[i]);
        }

        if ( max1 < max2 ) {
            ans1[cas] = ans2[cas] =  0;
        }
        else if ( max1 > max2 ) {
            ans1[cas] = ans2[cas] = 1;
        }
        else {
            ans1[cas] = 1;
            ans2[cas] = 0;
        }
    }
    for ( int i = 1 ; i <= T ; i++ ) {
        if ( ans1[i] ) cout << "Alice" << endl;
        else cout << "Bob" << endl;
        if ( ans2[i] ) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}