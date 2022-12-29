# Codeforces Round #689 (Div. 2, based on Zed Code Competition)

## [A. String Generation](https://codeforces.ml/contest/1461/problem/A)

[](./A.png)
- 题目大意：要求你构造一个只包含'a,b,c'三个字母的字符串，要求其回文子串的长度不能超过k
- 构造
  
```cpp
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);
#define LL long long
#define max_size (int)(2e5 + 10)


string ans[max_size];
int main ()
{
	IOS
	int T ; cin >> T;
	for ( int cas = 1 ;cas <= T ; cas++ )
	{
		int n , k ; cin >> n >> k;
		for ( int i = 1 ; i <= n ; i++ )
			ans[cas].push_back(i%3+'a');
	}
	for ( int i = 1 ; i <= T ; i++ )
		cout << ans[i] << endl;
}
```

## [B. Find the Spruce](https://codeforces.ml/contest/1461/problem/B)

[](./B.png)

- 题目大意：给定一个矩阵，求问矩阵当中有多少个符合题目所给的样例的排列规律
- 模拟
- 首先我们可以知道，所有的\*肯定都满足我们寻找的条件。接下来，我们需要寻找由这个\*出发的满足题目构造条件的图形。我们可以构建一个前缀和，表示以当前位置的\*作为结尾的最长前缀有多少个

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);
#define LL long long
#define max_size (int)(2e5 + 10)

LL ans[max_size];

int main()
{
	IOS
	int T ; cin >> T;
	for ( int cas = 1  ;cas <= T ; cas++ )
	{
		int n , m ;
		cin >> n >> m;
		string c[505];
		for ( int i = 1 ; i <= n ; i++ ) cin >> c[i] , c[i] = ' ' + c[i];
		LL res = 0 ;
		for ( int i = 1 ; i <= n ; i++ )
			for ( int j = 1 ; j <= m ; j++ )
				if ( c[i][j] == '*' )
					res++;
		int a[505][505];
		memset ( a , 0 , sizeof(a) );
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = 1 ; j <= m ; j++ )
			{
				a[i][j] = a[i][j-1];
				if ( c[i][j] == '*' ) a[i][j]++;
				else a[i][j] = 0 ;
			}
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = 1 ; j <= m ; j++ )
			{
				if ( a[i][j] == 0 ) continue;
				int x = i+1;
				int y = j+1;
				while ( x <= n && y <= m )
				{
					int d = x-i;
					if ( a[x][y] >= 1+2*d )
					{
						res++;
						x++ , y++;
					}
					else break;
				}
			}
		}
		ans[cas] = res;
	}
	for ( int i =1 ; i <= T ; i++ )
		cout << ans[i] << endl;
}
```

## [C. Random Events](https://codeforces.ml/contest/1461/problem/C)

[](./C.png)

- 题目大意：给定一个数列，并且告诉你会进行若干次排序，每次都会选择前面的x个元素进行排序，每次排序都有一定的几率，求问最后整个数列是排好顺序的几率是多少
- 模拟
- 要使得最后整个数列的顺序是排好的，那么就要求我们对数列排序是有效的。什么是有效的数列排序？就是当我们选择前面x个元素进行排序的时候，我们是有机会使得这个数列有序，并且我们可以根据条件概率去计算后面的排列概率。那么对于这道题，我们从后往前找到第一个$a[i]\neq i$的元素，后面选择前x个元素进行排序必须大于等于这个位置，这样的排序才有意义

```cpp
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);
#define LL long long
#define max_size (int)(2e5 + 10)

double ans[max_size];
int a[max_size];

int main ()
{
    IOS
    int T ; cin >> T;
    for ( int cas = 1  ;cas <= T ; cas++)
    {
        int n , m ;
        cin >> n >> m;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        int pos = 0;
        for ( int i = n ; i >= 1 ; i-- )
            if ( a[i] != i )
            {
                pos = i;
                break;
            }
        
        vector<pair<int,double> > v;
        for ( int i = 1 ; i <= m ; i++ )
        {
            int x ; double y;
            cin >> x >> y;
            v.push_back({x,y});
        }
        if ( pos == 0 ) { ans[cas] = 1.0 ; continue;}
        sort(v.begin(),v.end());
        double cur = 1.0;
        double res = 0.0;
        for ( auto tmp : v )
        {
            if ( tmp.first < pos ) continue;
            res += cur*tmp.second;
            cur *= 1.0 - tmp.second;
        }
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ )
        printf ( "%.6lf\n",ans[i] );
}
```

## [D. Divide and Summarize](https://codeforces.ml/contest/1461/problem/D)

[](./D.png)

- 题目大意：一开始有一个数列，每次我们会选择数列的$mid = \frac{max-min}{2}$，我们把小于等于mid的数字归一类，把大于mid的数字归为另外一类，每次我们都可以选择其中一类数字进行类似的操作。其中，我们把当前数列的和称为整个数列的value，求问题目给出的q个value当中我们是否能够顺利构造
- 分治
- 先对数列进行排序，用一个集合存放当前数列的和，然后我们对右半边的数列进行类似处理，对左半边的数列进行类似处理

```cpp
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);
#define LL long long
#define max_size (int)(2e5 + 10)

bool ans[max_size];
LL a[max_size];
LL sum[max_size];
set <LL> st;

void Build ( int l , int r )
{
    if ( l == r )
    {
        st.insert(a[l]);
        return ;
    }
    if ( a[l] == a[r] )
    {
        st.insert(a[l]*(r-l+1));
        return ;
    }
    st.insert(sum[r]-sum[l-1]);
    LL mid = a[l] + a[r] >> 1;
    int pos = upper_bound(a+l,a+r,mid) - a;
    
    Build( l , pos-1 );
    Build( pos , r );
    
}
int main ()
{
    IOS
    int T ; cin >> T;
    while (T--)
    {
        int n , q;
        cin >> n >> q;
        memset ( sum , 0 , (n+5)*sizeof(LL) );
        st.clear();
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        sort ( a+1 , a+1+n );
        for ( int i = 1 ; i <= n ; i++ ) sum[i] = sum[i-1] + a[i];
        Build(1,n);
        for ( int i = 1 ; i <= q ; i++ )
        {
            LL x ; cin >> x;
            if ( st.find(x) != st.end() )
                ans[i] = 1;
            else ans[i] = 0 ;
        }
        for ( int i = 1 ; i <= q ; i++ )
            if ( ans[i] ) cout << "Yes" << endl;
            else cout << "No" << endl;
    }
}
```

## [E. Water Level](https://codeforces.ml/contest/1461/problem/E)

[](./E.png)

- 题目大意：某公司的饮水机一开始有k升水，要求这个饮水机不论什么时候水位都必须在[l,r]的范围内。公司小王每天上班的时候会给饮水机添加y升水，公司每天稳定会消耗x升水。求问小王值班的t天当中，是否能够保证公司饮水机的水位保持在合法的范围内
- 模拟
- 如果$y<x$，那么我们只需要判断一下每天消耗(x-y)升水是否能够苟活到小王值班结束。注意我们需要考虑一下第一天是否能够加水
- 如果$y>x$，我们知道，经过若干天后，水位发生了循环，那就说明这个水位一定是合法的水位，那么接下来我们应该怎么去添加水呢？最简单的方法就是等到不得不加水的时候我们去加水

```cpp
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);
#define LL long long
#define max_size (int)(1e6 + 10)


LL k , l , r , t , x , y;
bool vis[max_size];
int main ()
{
    cin >> k >> l >> r >> t >> x >> y;
    if ( k < l || k > r ) {cout << "No" << endl;return 0;}

    if ( y < x )
    {
        if ( k + y > r ) k -= x , t--;
        if ( k < l ) cout << "No" << endl;
        else
        {
            LL days = ( k - l ) / ( x - y );
            if ( days < t ) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    else
    {
        bool flag = 0 ;
        while ( t > 0 )
        {
            if ( vis[k%x]) 
            {
                flag = 1;
                cout << "Yes" << endl;
                break;
            }
            vis[k%x] = 1;
            LL days = min ( t , (k-l) / x);
            k -= days * x ;
            t -= days;
            if ( t == 0 )
            {
                flag = 1;
                cout << "Yes" << endl;
                break;
            }
            t--;
            if ( k + y <= r ) k+=y;
            k -= x;
            if ( k < l || k > r ) 
            {
                flag = 1;
                cout << "No" << endl;
                break;
            }
        }
        if ( !flag ) cout << "Yes" << endl;
    }
    
}
```

## [F. Mathematical Expression](https://codeforces.ml/contest/1461/problem/F)

[](./F.png)

- 题目大意：给定n个数字并给定至多3种操作，求问怎么利用这些操作使得数字最后的运算结果最大
- DP
- (翻译官方题解)
- 首先我们可以先排除某些情况，比如说只有减法或者没有乘法的情况
- 对于同时有乘法和加法的情况，我们首先假设全都是加法。然后我们如果找到了中间某些串的乘积是非常大的话，那么毫无疑问我们应该使用乘法；不然的话，对于这个区间，我们可以使用DP进行解决，$dp_i$表示如果当前你站在i的最大答案值。现在我们相当于站在i想要转移到j，这就意味着i到j之间会有一个符号是乘号，j过后的位置就是一个加号

（以下官方代码）
```cpp
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);
#define LL long long
#define max_size (int)(2e5 + 10)

int n ; 
LL a[max_size];
LL dp[max_size] , pr[max_size];
char op[max_size];
string s;
const LL inf = 1e9;

int main ()
{
	IOS
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
	cin >> s;
	bool plus , minu , mul ;
	plus = minu = mul = 0 ;
	if ( s.length() == 1 )
	{
		cout << a[1] ;
		for ( int i = 2 ; i <= n ; i++ )
			cout << s[0] << a[i];
		cout << endl;
		return 0;
	}
	for ( auto x : s )
	{
		if ( x == '+' ) plus = 1;
		if ( x == '-' ) minu = 1;
		if ( x == '*' ) mul  = 1;
	}
	if ( !mul )
	{
		if ( !plus )
		{
			cout << a[1] ;
			for ( int i = 2 ; i <= n ; i++ )
				cout << "-" << a[i] ;
			cout << endl;
		}
		else
		{
			cout << a[1] ;
			for ( int i = 2 ; i <= n ; i++ )
				cout << "+" << a[i];
			cout << endl;
		}
	}
	else
	{
		if ( !plus )
		{
			cout << a[1];
			for ( int i = 2 ; i <= n ; i++ )
			{
				if ( a[i] == 0 )
					cout << "-" << a[i] ;
				else cout << "*" << a[i];
			}
			cout << endl;
		}
		else
		{
			int uk = 1;
			for ( int i = 1 ; i <= n+1 ; i++ )
				op[i] = '+';
			while ( uk <= n )
			{
				while ( uk <= n && a[uk] == 0 ) uk++;
				if ( uk == n+1 ) break;
				int left = uk;
				while ( uk <= n && a[uk] ) uk++;
				int right = uk - 1;
				while ( left <= right && a[left] == 1 ) left++;
				while ( left <= right && a[right] == 1 ) right--;
				if ( left > right ) continue;

				LL fac = 1;
				for ( int i = left ; i <= right ; i++ ) fac = min ( inf , fac*a[i] );
				if ( fac == inf )
				{
					for ( int i = left + 1 ; i <= right ; i++ )
						op[i] = '*';
					continue;
				}
				vector < pair<LL,pair<LL,LL> > > st;
				int j = left;
				while ( j <= right )
				{
					int l = j ;
					LL tmp = 1;
					if ( a[l] == 1 )
					{
						while ( j <= right && a[j] == 1 ) j++;
						tmp = j-l;
					}
					else
					{
						while ( j <= right && a[j] > 1 )
						{
							if ( j != l ) op[j] = '*';
							tmp = min ( inf , tmp*a[j] );
							j++;
						}
					}
					st.push_back({tmp,{l,j-1}});
 				}
				//for ( auto x : st ) cout << x.first << endl;
				for ( int i = 1 ; i <= st.size() ; i++ ) dp[i] = -inf;
				for ( int i = 1 ; i <= st.size() ; i++ )
				{
					if ( dp[i] < dp[i-1] + st[i-1].first )
					{
						pr[i] = i-1 ;
						dp[i] = dp[i-1] + st[i-1].first;
					}
					if ( i % 2 == 1 )
					{
						LL t = 1;
						for ( int j = i ; j <= st.size() ; j++ )
						{
							if ((j-i) % 2 == 0 ) t *= st[j-1].first;
							if ((j-i) % 2 == 0 && dp[j] < t + dp[i-1] )
							{
								pr[j] = i-1;
								dp[j] = t + dp[i-1];
							} 
						}
					}
				}
				int x = st.size();
				while (x)
				{
					int l = pr[x] + 1 , r = x;
					x = pr[x];
					if ( l < r )
						for ( int i = st[l-1].second.first + 1 ; i <= st[r-1].second.second ; i++ )
							op[i] = '*';
				}
			}
			cout << a[1] ;
			for ( int i = 2 ; i <= n ; i++ )
				cout << op[i] << a[i] ;
			cout << endl;
		}
	}
}
```
