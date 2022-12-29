# Educational Codeforces Round 99 (Rated for Div. 2)

## [A. Strange Functions](https://codeforces.ml/contest/1455/problem/A)

```CPP
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define LL long long
#define maxn (int)(2e5 + 10)

int a[maxn];
int ans[maxn];
int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        string s ;
        cin >> s;
        ans[cas] = s.length();
    }
    for ( int i = 1;  i  <= T ; i++ )
        cout << ans[i] << endl;
}
```

## [B. Jumps](https://codeforces.ml/contest/1455/problem/B)

```CPP
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define LL long long
#define maxn (int)(2e5 + 10)

int ans[maxn];
int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ;cas <= T ; cas++ )
    {
        int x ; cin >> x;
        int left = 1 , right = x+5;
        while ( left < right )
        {
            int mid = left + right >> 1;
            if ( 1ll * mid * (mid+1) / 2 == x )
            {
                left = mid;
                break;
            }
            if ( 1ll * mid * (mid+1) / 2 - x >= 2 )
                right = mid;
            else left = mid+1;
        }
        ans[cas] = left ;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}
```

## [C. Ping-pong](https://codeforces.ml/contest/1455/problem/C)

```CPP
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define LL long long
#define maxn (int)(2e5 + 10)

pair<int,int> ans[maxn];

int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        int x , y ; cin >> x >> y;
        ans[cas] = {x-1,y};
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i].first << " " << ans[i].second << endl;
}
```

## [D. Sequence and Swaps](https://codeforces.ml/contest/1455/problem/D)

```CPP
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define LL long long
#define maxn (int)(2e5 + 10)

int ans[maxn];
int a[505];
int b[505];
int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        int n , x ;
        cin >> n >> x;
        for ( int i = 1 ; i <= n ; i++ )
            cin >> a[i];
        for ( int i = 1 ; i <= n ; i++ )
            b[i] = a[i];
        sort ( b+1 , b+1+n );
        
        bool flag = 1;
        for ( int i = 1 ; i <= n ; i++ )
            if ( a[i] != b[i] )
            {
                flag = 0 ;
                break;
            }
        if ( flag ) ans[cas] = 0;
        else
        {
            int res = 1 << 30;
            int cur = x ;
            for ( int i = 1 ; i <= n ; i++ )
            {
                b[i] = x;
                cur = x ;
                for ( int j = 1 ; j <= n ; j++ )
                    if ( j != i ) b[j] = a[j];
                sort ( b+1 , b+1+n );
                int cnt = 0 ;
                flag = 1;
                for ( int j = 1 ; j <= n ; j++ )
                {
                    if ( a[j] == b[j] ) continue;
                    if ( a[j] <= cur )
                    {
                        flag = 0;
                    }
                    else
                    {
                        cnt++;
                        if ( b[j-1] > cur ) flag = 0;
                        cur = a[j];
                    }
                    if ( !flag ) break;
                }
                if ( flag ) res = min ( res , cnt );
            }
            if ( res == 1 << 30 ) ans[cas] = -1;
            else ans[cas] = res;
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}
```

## [E. Four Points](https://codeforces.ml/contest/1455/problem/E)

```CPP
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define LL long long
#define maxn (int)(2e5 + 10)


struct node {
    LL x , y;
}Node[5] , P[5];
bool vis[5];
LL ans[maxn];
LL res = 1ll << 60;

LL solve ()
{
    LL x1 = min ( P[1].x , P[3].x );
    LL x2 = max ( P[1].x , P[3].x );
    LL x3 = min ( P[2].x , P[4].x );
    LL x4 = max ( P[2].x , P[4].x );
    LL y1 = min ( P[1].y , P[2].y );
    LL y2 = max ( P[1].y , P[2].y );
    LL y3 = min ( P[3].y , P[4].y );
    LL y4 = max ( P[3].y , P[4].y );
    LL xl , xr , yl , yr;
    LL costx , costy;
    if ( x4 < x1 )
    {
        xl = xr = 0 ;
        costx = x2 - x3 + x1 - x4;
    }
    else 
    {
        xl = max ( x3 - x2 , 0ll );
        xr = x4 - x1;
        costx = x2 - x1 + x4 - x3;
    }

    if ( y4 < y1 )
    {
        yl = yr = 0 ;
        costy = y2 - y3 + y1 - y4;
    }
    else
    {
        yl = max ( 0ll , y3-y2);
        yr = y4 - y1;
        costy = y2 - y1 + y4 - y3;
    }
    
    LL tmp = costx + costy ;
    if ( yl > xr )
        tmp += 2ll * ( yl - xr );
    else if ( xl > yr )
        tmp += 2ll * ( xl - yr );
    return tmp;
}
void dfs ( int cnt )
{
    if ( cnt == 5 )
    {
        res = min ( res , solve() );
        return ;
    }
    for ( int i = 1 ; i <= 4 ; i++ )
    {
        if ( vis[i] ) continue;
        P[cnt] = Node[i];
        vis[i] = 1;
        dfs ( cnt+1 );
        vis[i] = 0 ;
    } 
}
int main ( )
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        for ( int i = 1 ; i <= 4 ; i++ ) cin >> Node[i].x >> Node[i].y;
        res = 1ll << 60;
        dfs(1);
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}
```

## [F. String and Operations](https://codeforces.ml/contest/1455/problem/F)

## [G. Forbidden Value](https://codeforces.ml/contest/1455/problem/G)
