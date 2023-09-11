#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
bool ans[maxn];


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        int a,b,c;
        cin >> a >> b >>c;
        int sum = a + b + c;
        int minx = min(a,b);
        minx = min(minx,c);

        if ( sum - minx >= 10 ) {
            ans[cas] = 1;
        } else {
            ans[cas] = 0 ;
        }

    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}