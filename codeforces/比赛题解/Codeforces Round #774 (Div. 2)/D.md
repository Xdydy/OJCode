# D. Weight the Tree

## Tag 

`树形dp` `*2000`

## 题目来源

[Codeforces Round #774 (Div. 2)](https://codeforces.ml/contest/1646)

## 题目大意

- 给你一棵树，要求你给这棵树的每个结点赋予权值，当一个结点的权值等于周围的点的权值之和时，这个结点被称为good结点。求最多能够有多少个good结点，当满足有多个good结点时，需要使得总体的权值最小

## 解题思路

- 我们首先知道，当一棵树的结点个数大于2时，共享同一条边的两个结点不可能同时为good结点
- 设某个结点为$u$，结点有两个状态：它是一个good结点以及它不是一个good结点，我们分别用$dp[u][0]$和$dp[u][1]$表示。我们维护每个状态的两个信息(p,s)，p表示该结点状态下的**所有子节点及自身**可以为父节点贡献多少个good结点，s表示该结点状态下**所有子节点和自身**可以为父节点贡献多少权值和。设其子节点为v，那么我们有如下状态转移方程

$$
dp[u][1] = \sum_v{dp[v][0]} \\
dp[u][0] = \sum_v{\max(dp[v][0], dp[v][1])}
$$

- 最后我们需要构建路径，我们只需要通过求得的$val$值代入根节点即可。所有的good结点的权值便是其所有连接的边的条数，所有非good结点的权值都是1


## AC Code


```cpp
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n ;
vector<int> G[maxn];
pair<int,int> dp[maxn][2];
int pa[maxn];

void dfs(int u, int fa)
{
    for ( auto v : G[u] ) 
    {
        if ( v == fa ) continue;
        pa[v] = u;
        dfs(v,u);
    }
}

pair<int,int> dfs2(int x, int y)
{
    if ( dp[x][y].first >= 0 ) return dp[x][y];
    dp[x][y].first = y;
    if ( y )
        dp[x][y].second = -(int)(G[x].size());
    else dp[x][y].second = -1;

    for ( auto v : G[x] )
    {
        if ( v == pa[x] ) continue;
        auto maxx = dfs2(v,0);
        if ( y == 0 ) maxx = max( maxx , dfs2(v,1));
        dp[x][y].first += maxx.first;
        dp[x][y].second += maxx.second;
    }
    return dp[x][y];
}

bool ans[maxn];
void build(pair<int,int> val, int u)
{
    if ( val == dfs2(u,0) ) 
    {
        ans[u] = 0;
        for ( auto v : G[u] ) 
        {
            if ( v == pa[u] ) continue;
            build(max(dfs2(v,0), dfs2(v,1)), v);
        }
    }
    else 
    {
        ans[u] = 1;
        for ( auto v : G[u] ) 
        {
            if ( v == pa[u] ) continue;
            build(dfs2(v,0), v);
        }
    }

}


int main ()
{
    IOS;
    cin >> n ;
    for ( int i = 1 ; i < n ; i++ )
    {
        int u , v; 
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if ( n == 2 )
    {
        cout << 2 << " " << 2 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 0 ; j <= 1 ; j++ )
            dp[i][j] = {-1,-1};
    pa[1] = 0 ;
    dfs(1,0);
    auto res = max(dfs2(1,0), dfs2(1,1));
    cout << res.first << " " << -res.second << endl;
    build(res,1);

    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( ans[i] ) cout << G[i].size() << " ";
        else cout << 1 << " " ;
    }
    cout << endl;
}
```