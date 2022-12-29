#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long 

//主席树主要用来查询[l,r]区间内第k小的数字
int t[max_size<<5] , lc[max_size<<5] , rc[max_size<<5];
int a[max_size<<5] , b[max_size<<5];//原序列与离散排序序列
int T[max_size];//插入了i个点的树的根节点编号
int nodenum;
int Build ( int l , int r )
{
    int num = ++nodenum;
    if ( l != r )
    {
        int mid = l + r >> 1;
        lc[num] = Build ( l ,  mid );
        rc[num] = Build ( mid+1 , r );
    }
    return num;
}
int update ( int pre , int l , int r , int x )
{
    int num = ++nodenum;
    lc[num] = lc[pre] , rc[num] = rc[pre] , t[num] = t[pre] + 1;
    if ( l != r )
    {
        int mid = l + r >> 1;
        if ( x <= mid ) lc[num] = update ( lc[pre] , l , mid , x );
        else rc[num] = update ( rc[pre] , mid+1 , r , x );
    }
    return num;
}
//uv为待查询的区间左端点对应子树的根节点，右端点对应子树的根节点。
//lr当前的区间端点，k为第k小的数
int query ( int u , int v , int l , int r , int k )
{
    if ( l == r ) return b[l];
    int mid = l + r >> 1 , num = t[lc[v]] - t[lc[u]];
    if ( num >= k ) return query ( lc[u] , lc[v] , l , mid , k );
    else return query ( rc[u] , rc[v] , mid+1 , r , k - num );
}
int main ()
{
    int n , m;
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> a[i] , b[i] = a[i];
    sort ( b+1 , b+n+1 );
    int cnt = unique ( b+1 , b+n+1 ) - b - 1;
    T[0] = Build ( 1 , cnt );
    for ( int i = 1 ; i <= n ; i++ )
    {
        int tmp = lower_bound(b+1 , b+1+cnt , a[i]) - b;
        T[i] = update ( T[i-1] , 1 , cnt , tmp );
    }
    while ( m-- )
    {
        int q , w , e;
        cin >> q >> w >> e;
        int res = query (T[q-1] , T[w] , 1 , cnt , e);
    }
}