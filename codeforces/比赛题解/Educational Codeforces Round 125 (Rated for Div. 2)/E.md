# E. Star MST

## Tag

`dp` `rating2200`

## 题目来源

[Educational Codeforces Round 125 (Rated for Div. 2)](https://codeforces.ml/contest/1657)

## 题目大意

- 考虑这么一张含有n个节点的完全无向连通图，每条边的边权的范围都是从1到k
- 定义这样的一张图是beautiful的: 节点1和它临近的点的边权之和等于图的最小生成树的边权之和，也就是说，1节点和周围的节点连起来可以组成最小生成树。给定n和k，求问这样的图有多少种

## 解题思路

- 对于节点编号大于1的两个节点，他们的边权必须满足$w_{x,y}\ge\max(w_{1,x}, w_{1,y})$，不然的话，就不能直接通过节点1和它相邻的节点连起来构成最小生成树了。也就是说，与节点1直接相连的点的边权必须是比较小的权值
- 现在我们设$dp[i][j]$表示已经有i个节点与1相连，并且他们最大的边权是j的图的个数。那么对于继续插进来的与节点1相连的边权为$j+1$的节点（假设他们的个数为t），从剩下的节点取出t个节点与节点1相连的取法就有$C_{n-1-i}^{n-1-i-t}$个，这些新插进来的节点与原先的与节点1相连的i个节点的边权的取值范围就是$[j+1,k]$，一共就有$k-j$种取值方案，上述的边的个数设为e。比如新插入1个节点，那么e就是i，再插入一个，e就加上i+1(因为得算上上一次插入的节点)
- 这样一来我们的状态转移方程便是

$$
dp[i+t][j+1] += dp[i][j] * C_{n-i-1}^{t} * (k-j)^e
$$

## AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

const LL mod = 998244353;

LL fac[305];
LL inv[305];

LL quickpow(LL n , LL k) {
    LL res = 1;
    while(k)
    {
        if (k&1) res = res * n % mod;
        k >>= 1;
        n = n * n % mod;
    }
    return res;
}

LL getInv(LL x) {
    return quickpow(x, mod-2);
}

void init() {
    fac[0] = 1;
    for ( int i = 1 ; i <= 300 ; i++ )
        fac[i] = fac[i-1] * i % mod;
    inv[300] = getInv(fac[300]);
    for ( int i = 299 ; i >= 0 ; i-- )
        inv[i] = inv[i+1] * (i+1) % mod;    
}

LL C(LL n, LL k) {
    if ( n < k ) return 0;
    return fac[n] * inv[k] % mod * inv[n-k] % mod;
}

LL dp[305][305];

int main ()
{
    init();
    int n , k ;
    cin >> n >> k ;;
    dp[0][0] = 1;
    n--;
    for ( int i = 0 ; i <= n ; i++ )
    {
        for ( int j = 0 ; j < k ; j++ )
        {
            LL pw = k-j;
            LL e = 0;
            for ( int t = 0 ; t <= n-i ; t++ )
            {
                dp[i+t][j+1] += dp[i][j] * C(n-i, t) % mod * quickpow(pw, e) % mod;
                dp[i+t][j+1] %= mod;
                e += i+t;
            }
        }
    }
    cout << dp[n][k] << endl;
}
```