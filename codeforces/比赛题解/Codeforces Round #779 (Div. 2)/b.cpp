#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define LL long long
#define maxn (int)(1e6 + 10)
#define FFF freopen("out", "w", stdout);

const LL mod = 998244353;

int n;
int a[maxn];
LL ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        cin >> n;
        if ( n % 2 ) 
            ans[cas] = 0 ;
        else 
        {
            LL res = 1;
            int cnt = n / 2;
            for ( int i = 1 ; i <= cnt ; i++ )
            {
                res *= i;
                res %= mod;
            }
            ans[cas] = res * res % mod;
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}