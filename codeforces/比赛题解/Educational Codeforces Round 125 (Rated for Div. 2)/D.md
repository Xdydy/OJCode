# D. For Gamers. By Gamers.

## Tag

`前缀和` `rating2000`

## 题目来源 

[Educational Codeforces Round 125 (Rated for Div. 2)](https://codeforces.ml/contest/1657)

## 题目大意

- 给你n种勇士，你每次战斗只能派一种类型的勇士上场，每个勇士有如下的属性:
  - $c_i$ 代表勇士的价格
  - $d_i$ 代表勇士的攻击力
  - $h_i$ 代表勇士的生命值

- 你可以买多个这样的勇士，但是最后的价钱不能超过C
- 现在你要面对m个恶魔，每个恶魔都会有如下属性
  - $D_j$ 代表恶魔的攻击力
  - $H_j$ 代表恶魔的生命值

- 对于每一次的战斗，勇士的攻击力和恶魔的攻击力都是连续性的，获胜的方法为，在恶魔击杀任何一名勇士之前击杀恶魔
- 求问面对每个恶魔，你是否能够有一种办法击败他们，如果有，最小的花费应该是多少

## 解题思路

- 首先我们假设拥有某种类型的勇士$x$个，那么击败恶魔的方程便是

$$
\frac{D_j}{h_i} \lt \frac{d_i}{H_j} *x 
$$

移项，得到

$$
d_i * h_i * x > D_j * H_j
$$

由此可见，我们只需要关注每个勇士或者恶魔的攻击力和生命值的乘积即可

- 接下来我们设$bst_c$表示花费为不超过c的情况下，能够造成的最大乘积，考虑到可以买多个勇士的影响，我们对于每个花费低的勇士都尝试买多个勇士看看能不能优于买较少的花费高的勇士，这样的复杂度为

$$
\frac{C}{1} + \frac{C}{2} + \dot + \frac{C}{C} = C\log C
$$

对于没有访问到的数据，我们可以用前缀和求出

- 最终我们用二分法可以得到每个恶魔花费的最小成本了

## AC代码
```cpp
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);



int n , C ;
int m ;
LL bst[maxn];

LL ans[maxn];




int main ()
{
    IOS;
    cin >> n >> C ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        LL c , d , h;
        cin >> c >> d >> h;
        bst[c] = max(bst[c], d*h);
    }

    for ( int c = 1 ; c <= C ; c++ )
        for ( int xc = c ; xc <= C ; xc += c )
            bst[xc] = max(bst[xc], bst[c] * (xc/c));
    for ( int i = 1 ; i <= C ; i++ )
        bst[i] = max(bst[i], bst[i-1]);

    cin >> m ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        LL D , H;
        cin >> D >> H;
        int pos = upper_bound(bst+1, bst+1+C, D*H) - bst;
        if ( pos == C+1 )
            ans[i] = -1;
        else ans[i] = pos;
    }
    for ( int i = 1 ; i <= m ; i++ )
        cout << ans[i] << " ";
    cout << endl;
}
```