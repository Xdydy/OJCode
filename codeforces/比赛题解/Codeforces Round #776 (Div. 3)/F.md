# F. Vitaly and Advanced Useless Algorithms

## Tag

`dp` `贪心` `rating2200`

## 题目链接

https://codeforces.ml/contest/1650/problem/F

## 题目大意

- 有n个任务需要完成，每个任务都有对应的ddl，记为数组a，每个任务的完成度必须到达100\%才算完工
- 现在有m个选择，每个选择会对应3个属性
  - $e$ 表示该选择可以解决哪项任务
  - $t$ 表示该选择会耗费自己多长时间
  - $p$ 表示该选择会促使工作进度完成多少个百分比

- 现在问能否通过合理的选择顺序，使得每个工作都不耽搁
- 数据范围
  - $1 \le n,m \le 10^5$
  - $1 \le a_i \le 10^9$ ，$a_1 \le a_2 \le \dots \le a_n$
  - $1 \le e_i \le n$
  - $1 \le t_i \le 10^9$
  - $1 \le p_i \le 100$

## 解题思路

- 贪心。我们会首先解决ddl在最前面的任务，并且我们对于这个任务，应该尽可能在最早的时间去解决它，那么对于每一个任务，我们应该贪心地求算出其被解决的最短时间。在这个最短的时间的基础上，距离ddl的时间将会节省下来帮助我们完成后续的任务
- dp。对于一个任务来说，我们把所有能够推进它的进度的选项进行归档，做一个01背包问题。设$dp(i,j)$表示前$i$个选项进度为$j$的最小时间，那么我们有
  - $dp(i,j) \ge dp(i-1,j), dp(i,j) \ge dp(i, j+1)$
  - $dp(i,j) = \min(dp(i,j), dp(i-1, j-p)+t)$, $p$表示第$i$个进度的推进程度，$t$表示第$i$个进度耗费的时间

## AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e5 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m;
int a[maxn];
struct node 
{
    LL t;
    int p ;
    int no;
};
vector<node> op[maxn];
LL dp[maxn][115];

int main()
{
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for ( int i = 1 ; i <= n ; i++ )
            op[i].clear();
        for (int i = 1; i <= m; i++)
        {
            int e, t, p;
            cin >> e >> t >> p;
            if (op[e].empty())
                op[e].push_back({0, 0});
            op[e].push_back({t, p, i});
        }
        LL last = a[1];
        bool flag = 1;
        vector<int> ans;
        for (int task = 1; task <= n; task++)
        {
            int len = op[task].size() - 1;
            if ( len <= 0 )
            {
                flag = 0 ;
                break;
            }
            for (int i = 0; i <= len; i++)
                for (int j = 1; j <= 105; j++)
                    dp[i][j] = 1ll << 40;
            for ( int i = 0 ; i <= len ; i++ )
                dp[i][0] = 0;
            for (int i = 1; i <= len; i++)
            {
                auto ss = op[task][i];
                LL t = ss.t;
                int p = ss.p;
                for (int j = 100 ; j >= 1 ; j-- )
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j+1]);
                    if (j >= p)
                    {   
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - p] + t);
                    }
                }
            }
            if (dp[len][100] > last)
            {
                flag = 0;
                break;
            }
            else
            {
                last = last - dp[len][100] + a[task + 1] - a[task];
                int x = 100;
                for (int i = len; i >= 1; i--)
                {
                    if ( x <= 0 ) break;
                    auto ss = op[task][i];
                    LL t = ss.t;
                    int p = ss.p;
                    if (dp[i][x] == dp[i - 1][x])
                        continue;
                    ans.push_back(ss.no);
                    x -= p;
                }
            }
        }
        if (flag)
        {
            cout << ans.size() << endl;
            for ( auto x : ans )
                cout << x << " ";
            cout << endl;
        }
        else cout << -1 << endl;
    }
}
```