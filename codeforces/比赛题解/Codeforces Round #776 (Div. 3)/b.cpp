#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
LL ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        LL  l ,r ;
        LL a ;
        cin >> l >> r >> a;
        if ( r < a || a == 1 )
        {
            ans[cas] = r;
        }
        else 
        {
            LL res1 = r / a + r % a ;
            LL x = r;
            LL tmp = r % a ;
            LL res2 = 0 ;
            if ( x - tmp - 1 >= l )
            {
                res2 = r / a - 1 + a - 1;
            }
            ans[cas] = max(res1, res2);
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}