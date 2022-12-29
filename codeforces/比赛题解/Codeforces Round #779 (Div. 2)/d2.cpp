#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
int l , r;
LL ans[maxn];

int solve()
{
    int mul = 1;
    set<int> s;
    for ( int i = 1 ; i <= n ; i++ )
        s.insert(a[i]);
    set<int> s2;
    for ( ; l % 2 == 0 && r % 2 == 1 ; l >>= 1, r >>= 1, mul <<= 1 )
    {
        s2.clear();
        for ( auto x : s ) 
            s2.insert(x>>1);
        swap(s,s2);
    }

    int ans = l;;
    if ( l % 2 == 0 ) ans = r;

    for ( int x : s )
    {
        if ( s.find(x^1) == s.end() )
        {
            int cur = x^ans;
            bool flag = 1;
            for ( int i : s )
            {
                int tmp = cur ^ i ;
                if ( tmp < l || tmp > r )
                {
                    flag = 0;
                    break;
                }
            }
            if ( flag )
            {
                ans = cur;
                break;
            }
        }
    }
    return ans*mul;
}

int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        cin >> l >> r;
        n = r - l  + 1;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        ans[cas] = solve();
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}