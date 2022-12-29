# D. Integral Array

## Tag

`暴力`

## 题目来源

[Codeforces Round #775 (Div. 2, based on Moscow Open Olympiad in Informatics)](https://codeforces.ml/contest/1649)

## 题目大意

- 判断一个数组是不是满足如下情形：任选两个数组中的元素$x,y,x\ge y, \lfloor\frac{x}{y}\rfloor$也在数组当中

## 解题思路

-  我们知道

$$
y \times \lfloor\frac{x}{y}\rfloor \le x 
$$
$$
y \times \lfloor\frac{x}{y}\rfloor + y \gt x 
$$


那么我们假设现在这样一个数$r$, $r\notin a$，那么所有的数字$x$，$r\times y\le x \lt (r+1)\times y$都不能够存在于a当中，这样一来，我们可以枚举数组中拥有的数字$y$,再枚举数组中没有的数字$r$，从而判断在相应的区间内有没有非法的数字

- 对于非法数字的检测，我们可以采用前缀和的方式
- 如果$r\times y > c$，那么其实后面的数字已经不需要讨论了

## AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, c;
int a[maxn];
bool ans[maxn];
bool vis[maxn];

int pre[maxn];
int main()
{
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        cin >> n >> c;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(vis, 0, sizeof(bool) * (c + 5));
        memset(pre, 0, sizeof(int) * (c + 5));
        for (int i = 1; i <= n; i++)
            vis[a[i]] = 1;
        for (int i = 1; i <= c; i++)
            pre[i] = pre[i - 1] + vis[i];
        bool flag = 1;
        
        for ( int i = 1 ; i <= c ; i++ )
        {
            if ( !vis[i] ) continue;
            int y = i ;
            for ( int r = 1 ; r <= c && y*r <= c ; r++ )
            {
                if ( vis[r] ) continue;
                int st = r*y ;
                int ed = min((r+1)*y, c+1);
                if ( pre[ed-1] - pre[st-1] > 0 ) 
                {
                    flag = 0 ;
                    break;
                } 
            }
            if (!flag) break;
        }
        ans[cas] = flag;
    }
    for (int i = 1; i <= T; i++)
        if (ans[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
}
```