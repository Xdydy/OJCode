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
        int x[4],y[4];
        for ( int i = 1 ; i <= 3 ; i++ ) {
            cin >> x[i] >> y[i];
        }
        sort(x+1,x+1+3);
        sort(y+1,y+1+3);
        if ( x[1] != x[2] && x[2] != x[3] ) {
            ans[cas] = 1;
        }
        else if ( y[1] != y[2] && y[2] != y[3] ) {
            ans[cas] = 1;
        }
        else {
            ans[cas] = 0 ;
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}