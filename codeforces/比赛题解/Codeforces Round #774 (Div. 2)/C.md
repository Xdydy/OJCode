# C. Factorials and Powers of Two

## Tag 

`枚举` `暴力`

## 题目来源

[Codeforces Round #774 (Div. 2)](https://codeforces.ml/contest/1646)

## 题目大意

- 求问一个数能拆成最少多少个powerful的数字的和，powerful的数的定义为这个数要么是2的次方，要么是某个数的阶乘，如果没有方案，则输出-1

## 解题思路

- 我们知道一个数一定能够通过2的n次方的和加起来，比如6(110)，$6 = 2^1 + 2^2$，因此不存在输出-1的情况
- 现在我们需要知道能否通过若干个阶乘的结果来得到最优的答案，我们知道，$15! \gt 10^{12}$，因此我们只需要不超过15的阶乘的值
- 那么需要多少个阶乘呢？我们可以通过二进制进行枚举，复杂度为$2^{15}$，表示我们需要某个数的阶乘，例如(11100)表示我们同时获得阶乘$fac[2], fac[3], fac[4]$的值
- 原先的数减去这些个阶乘的数字之后，剩下的就只需要看剩下的数二进制中有多少个1了

## AC Code

```cpp
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define LL long long
#define maxn (int)(2e6 + 10)
#define FFF freopen("out", "w", stdout);

LL n;
int a[maxn];
int ans[maxn];

LL fac[20];
void init()
{
    fac[0] = 1;
    for ( int i = 1 ; i <= 15 ; i++ )
        fac[i] = fac[i-1] * i;
    return ;
}

int check(LL x )
{
    int cnt = 0 ;
    while ( x)
    {
        if( x & 1 )
            cnt++; 
        x >>= 1;
    }
    return cnt;
}

int main ()
{
    IOS;
    init();
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        cin >> n;
        int minx = check(n);
        for ( int i = 8 ; i <= 1 << 15 ; i+=8 )
        {
            LL tmp = n ;
            int cnt = 0 ;
            for ( int j = 0 ; j <= 15 ; j++ )
                if ( (1 << j) & i ) 
                {
                    cnt++;
                    tmp -= fac[j];
                }
            if ( tmp < 0 ) break;
            minx = min(minx, cnt + check(tmp));
        }
        ans[cas] = minx;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}
```