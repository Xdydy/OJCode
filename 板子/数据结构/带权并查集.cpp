#include <iostream>
#include <stdio.h>
using namespace std;

const int MAXN = 50005;

int fa[MAXN], rela[MAXN];
int n, k, ans;

void init()
{
    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
        rela[i] = 0;
    }
    ans = 0;
}

int find(int x)
{
    if(x == fa[x])
      return x;
    else
    {
        int temp = fa[x];
        fa[x] = find(fa[x]);
        rela[x] = (rela[x] + rela[temp]) % 3;
        return fa[x];
    }
}

//以下的r均为处理过的relation，0表示同类，1表示x吃y，2表示x被y吃
//也就是说这里的r为题目所给编号-1
void merge(int r, int x, int y)
{
    int fx = find(x), fy = find(y);
    if(fx != fy)
    {
        fa[fx] = fy;
        rela[fx] = (rela[y] - rela[x] + r + 3) % 3;//+3是为了防止这里相减产生负数
    }
}

bool check(int r, int x, int y)
{
   if(x > n || y > n)
        return false;
   if(r == 1 && x == y)
    return false;
   if(find(x) == find(y))
   {
       int relation = ((rela[x] - rela[y]) % 3 + 3) % 3;//根据前面正确描述得出的正确的关系
       return relation == r;
   }
   else
    return true;
}

int main()
{
    scanf("%d%d", &n, &k);
    init();
    while(k--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--;
        if(check(a, b, c))
            merge(a, b, c);
        else
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}

/*动物王国中有三类动物A，B，C，构成环形：A吃B，B吃C，C吃A。

现有N个动物，从1开始编号，每个动物都是A，B，C中的一种，但我们并不知道是哪一种。

用两种说法描述这N个动物的食物链关系：

1 X Y 表示X和Y是同类
2 X Y 表示X吃Y

给出K句话，有些是真的，有些是假的，满足下列任一条件即为假话，否则是真话：

当前的话与之前的某些真话冲突
当前的话中X或Y比N大
当前的话表示X吃X

输出假话的总数。
*/