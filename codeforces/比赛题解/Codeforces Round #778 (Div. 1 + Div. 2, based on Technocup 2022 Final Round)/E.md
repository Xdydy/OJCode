# E. Arithmetic Operations

## Tag 

`dp` `根号分治` `rating2300`

## 题目来源

[Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)](https://codeforces.ml/contest/1654)

## 题目大意

- 给定一个数列a，每次操作可以任意变动a的其中一个数，求最少的操作次数将a变成等差数列

## 解题思路

- 我们与其去计算最小的变动次数，不如我们直接计算最大的不用变动的元素
- 设$d$为最终的等差数列中的公差，$m$为整个数列的最大值，假定$d$只能取正整数，我们可以根据$d$的取值范围对如下的情况进行分类讨论
  - $d \lt \sqrt{m}$ 时，由于这个数字范围很小，因此我们可以直接暴力枚举$d$，时间复杂度为$O(n\sqrt{m})$
  - $d \ge \sqrt{m}$ 时，那么对于两个间隔较远的数，比如$i,j$如果$j \gt i +\sqrt{m}$，那么两个数字之间必定要有一个数字发生改变，因为前面我们已经假设了公差的最大值不会超过$m$，两个数字距离这么远还一个都不改，那么会有两个数之间的差值$a_j-a_i \ge \sqrt{m}*d \gt m$显然是不可能的。那么我们只需要在一定的长度范围内，即$i,j$不要离得太远去求算他们在相同的公差$d$的情况下的最长序列。设$dp[i][d]$表示前$i$个数当中，公差为$d$的最长序列，我们再用一个滑动窗口来解决这个问题

## AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int n ;
int a[maxn];
int S = 70;

int b[100005*70];
unordered_map<int,int> dp[maxn];

int solve() 
{
    int res = 0 ;
    for ( int d = 0 ; d < S ; d++ )
    {
        for ( int i = 1 ; i <= n ; i++ )
            res = max(res, ++b[a[i]+(n-i)*d]);
        for ( int i = 1 ; i <= n ; i++ )
            b[a[i]+(n-i)*d] = 0;
    }

    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = max(1, i-100005/S) ; j < i ; j++ )
        {
            int d = (a[i]-a[j]) / (i-j);
            int r = (a[i]-a[j]) % (i-j);
            if ( r == 0 && d >= S )
            {
                dp[i][d] = max(dp[i][d], dp[j][d]+1);
                res = max(res, dp[i][d]+1);
            }
        }
    }
    for ( int i = 1 ; i <= n ; i++ )
        dp[i].clear();

    return res;
}

int main ()
{
    IOS;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    int ans = solve();
    reverse(a+1, a+1+n);
    ans = max(ans, solve());
    cout << n-ans << endl;
}
```