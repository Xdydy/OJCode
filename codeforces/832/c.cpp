#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
bool ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];

        int minx = 1 << 30;
        for ( int i = 1 ; i <= n ; i++ ) {
            minx = min(minx, a[i]);
        }
        if ( a[1] == minx ) {
            ans[cas]  = 0 ;
        }
        else {
            ans[cas] = 1;
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "Alice" << endl;
        else cout << "Bob" << endl;
}