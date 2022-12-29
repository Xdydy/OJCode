# C.Weird Sum

## Tag

`点贡献`

## 题目来源

[Codeforces Round #775 (Div. 2, based on Moscow Open Olympiad in Informatics)](https://codeforces.ml/contest/1649)

## 题目大意

给定一个$n \times m$的表格，表格的元素代表着颜色的种类，求问所有相同种类的颜色的距离和，定义两个表格之间的距离为它们的横坐标和纵坐标的差之和，例如(1,2)到(3,3)的距离为3

## 解题思路

- 我们先考虑某种颜色，比如1。1对答案的贡献就是任意的两个1之间的横坐标的差值的和对答案的贡献 加上 任意的两个1之间的纵坐标的差值的和对于答案的贡献。更加详细一点，假设第$i$个1的坐标为$(x_i, y_i)$，那么1对答案的贡献就是

$$
\sum_{i}\sum_{j}{\left|x_i-x_j\right|} + \sum_{i}\sum_{j}{\left|y_i-y_j\right|}
$$

- 现在我们单独考虑$x$坐标下的答案，由于上述式子的复杂度是$O(n^2)$的，因此我们需要考虑每个点对于答案的贡献值
- 考虑1的$x$轴坐标中的相邻两个点的距离对于答案的贡献，即这段距离会有哪几对点的连线经过，那么很显然便是这段距离的左边的点的个数乘上右边的点的个数,即

$$
\sum_{i}\sum_{j}{\left|x_i-x_j\right|} = \sum_{i=2}^n{(x_i-x_{i-1})\times (i-1)\times(n-i+1)}
$$

n表示1的个数

## AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define LL long long
#define maxn (int)(1e6 + 10)
#define FFF freopen("out", "w", stdout);

int n , m;
vector<int> mp[maxn];
vector<int> rr[maxn], cc[maxn];

int main ()
{
    IOS;
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ ) 
    {
        mp[i].push_back(0);
        for ( int j = 1 ; j <= m ; j++ )
        {
            int x ; cin >> x;
            rr[x].push_back(i);
            mp[i].push_back(x);
        }
    }
    for ( int j = 1 ; j <= m ; j++ )
    {
        for ( int i = 1 ; i <= n ; i++ )
        {
            int x = mp[i][j];
            cc[x].push_back(j);
        }
    }
    LL ans = 0;
    for ( int i = 1 ; i <= 100000 ; i++ )
    {
        if ( rr[i].size() > 1 )
        {
            for ( int j = 1 ; j < rr[i].size() ; j++ )
            {
                LL len = rr[i][j] - rr[i][j-1];
                ans += 1ll * (rr[i].size() - j ) * len * j;
            }
        }
        if ( cc[i].size() > 1 )
        {
            for ( int j = 1 ; j < cc[i].size() ; j++ )
            {
                LL len = cc[i][j] - cc[i][j-1];
                ans += 1ll * (cc[i].size() - j) * len * j;
            }
        }
    }
    cout << ans << endl;

}
```

