#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
LL B, x, y;
LL ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        cin >> n >> B >> x >> y;
        LL res = 0 ;
        LL cur = 0;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( cur + x <= B )
            {
                cur += x;
                res += cur;
            }
            else 
            {
                cur -= y;
                res += cur;
            }
        }
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}