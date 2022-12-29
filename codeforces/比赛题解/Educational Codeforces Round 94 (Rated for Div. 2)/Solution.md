#  Educational Codeforces Round 94 (Rated for Div. 2)

## A String Similarity

-  https://codeforces.ml/problemset/problem/1400/A
-  AC code
-  构造

```cpp
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(1e6+10)
#define MAX (int)(1e5+7)

int qread()
{
	char c; int s=0,t=1; while ((c=getchar())<'0' || c>'9') (c=='-' && (t=-1));
	do s=s*10+c-'0'; while ((c=getchar())>='0' && c<='9'); return s*t;
}

int main ()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while ( T-- )
    {
        int n ; cin >> n;
        string s ; cin >> s;
        for ( int i = 1 ; i <= n ; i++ )
            cout << s[n-1] ;
        cout << endl;
    }
}
```

## B. RPG Protagonist

- https://codeforces.ml/problemset/problem/1400/B
- AC code
- 贪心

```cpp
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(1e5+10)
#define MAX (int)(1e5+7)
int qread()
{
	char c; int s=0,t=1; while ((c=getchar())<'0' || c>'9') (c=='-' && (t=-1));
	do s=s*10+c-'0'; while ((c=getchar())>='0' && c<='9'); return s*t;
}

int ans[max_size];
int main ()
{
	ios::sync_with_stdio(0);
	int T ; cin >> T;
	for ( int cas = 1 ; cas <= T ; cas++ )
	{
		LL p , f ; cin >> p >> f;
		LL cnts , cntw ; cin >> cnts >> cntw;
		LL s , w ; cin >> s >> w;
		LL s1 , s2 , w1 , w2;
		LL maxx = 0 ;
		if ( s > w ) swap ( s , w ) , swap ( cnts , cntw );
		for ( int i = 0 ; i <= cnts ; i++ )
		{
			s1 = min ( 1ll*i , p / s );
			w1 = min ( cntw , (p - s * s1) / w );
			s2 = min ( cnts - s1 , f / s );
			w2 = min ( cntw - w1 , (f - s * s2) / w );
			maxx = max ( maxx , s1 + s2 + w1 + w2 );
		}
		ans[cas] = maxx;
	}
	for ( int i  =1 ; i <= T ; i++ )
	cout << ans[i] << endl;
}
```

## C. Binary String Reconstruction

- https://codeforces.ml/problemset/problem/1400/C
- AC code
- 构造，贪心

```cpp
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(1e5+10)
#define MAX (int)(1e5+7)
int qread()
{
	char c; int s=0,t=1; while ((c=getchar())<'0' || c>'9') (c=='-' && (t=-1));
	do s=s*10+c-'0'; while ((c=getchar())>='0' && c<='9'); return s*t;
}

int main ()
{
    ios::sync_with_stdio(0);
    int T ; cin >> T;
    while ( T-- )
    {
        string s ; cin >> s;
        int x ; cin >> x;
        int n = s.length();
        string w = string ( n , '1' );
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( s[i] == '0')
            {
                if ( i >= x ) w[i-x] = '0';
                if ( i + x < n ) w[i+x] = '0';
            }
        }
        string res = w;
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( (i >= x && w[i-x] == '1') || (i + x < n && w[i+x] == '1') )
                res[i] = '1';
            else res[i] = '0';
        }
        if ( res == s )
            cout << w << endl;
        else cout << "-1" << endl;
    }
}
```

## D. Zigzags

- https://codeforces.ml/problemset/problem/1400/D
- AC code
- dp，前缀和

```cpp
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(3e3+10)
#define MAX (int)(1e5+7)
int qread()
{
	char c; int s=0,t=1; while ((c=getchar())<'0' || c>'9') (c=='-' && (t=-1));
	do s=s*10+c-'0'; while ((c=getchar())>='0' && c<='9'); return s*t;
}

LL ans[105];
int cntleft[max_size][max_size] , cntright[max_size][max_size];
int main ()
{
	ios::sync_with_stdio(0);
	int T ; cin >> T;
	for ( int cas = 1 ; cas <= T ; cas++ )
	{
		int n ; cin >> n;
		int a[max_size];
		for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
		memset ( cntleft , 0 , sizeof(cntleft) );
		memset ( cntright , 0 , sizeof(cntright) );
		for ( int i = 1 ; i <= n ; i++ )
		{
			memcpy ( cntleft[i] , cntleft[i-1] , sizeof(cntleft[i]) );
			cntleft[i][a[i]]++;
		}
		for ( int i = n ; i >= 1 ; i-- )
		{
			memcpy ( cntright[i] , cntright[i+1] , sizeof(cntright[i]) );
			cntright[i][a[i]]++;
		}
		LL res = 0;
		for ( int j = 1 ; j <= n ; j++ )
			for ( int k = n ; k > j ; k-- )
				res += 1ll * cntleft[j-1][a[k]] * cntright[k+1][a[j]];
		ans[cas] = res;
	}
	for ( int i = 1 ; i <= T ; i++ )
		cout << ans[i] << endl;
}
```

## E. Clear the Multiset

- https://codeforces.ml/problemset/problem/1400/E
- AC code
- 分治

```cpp
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(5e3+10)
#define MAX (int)(1e5+7)

int qread()
{
	char c; int s=0,t=1; while ((c=getchar())<'0' || c>'9') (c=='-' && (t=-1));
	do s=s*10+c-'0'; while ((c=getchar())>='0' && c<='9'); return s*t;
}

const int inf = 0xfffffff;
int a[max_size];
int solve ( int l , int r )
{
    int minx = inf;
    int cnt = 0;
    for ( int i = l ; i <= r ; i++ )
        minx = min ( minx , a[i] );
    cnt += minx;
    for ( int i = l ; i <= r ; i++ )
        a[i] -= minx ;
    
    int i = l;
    while ( i <= r )
    {
        int left = 0 , right = 0;
        if ( a[i] != 0 )
        {
            left = i;
            while ( a[i] != 0 )
                right = i , i++ ;
            cnt += solve(left , right );
        }
        i++;
    }
    return min ( cnt , r - l + 1 );
}

int main ()
{
    ios::sync_with_stdio(0);
    int n ; cin >> n;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    cout << solve(1,n) << endl;
}
```