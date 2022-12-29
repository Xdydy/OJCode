#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

LL ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        int x , y;
        cin >> x >> y;
        if ( x == 0 && y == 0 )
        {
            ans[cas] = 0 ;
            continue;
        }
        int res = sqrt(x*x + y*y);
        if ( res*res == x*x + y*y )
            ans[cas] = 1;
        else ans[cas] = 2;
        
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}