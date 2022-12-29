#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(1e6+10)
#define MAX (int)(1e5+7)

int qread()
{
	char c; int s=0,t=1; while ((c=getchar())<'0' || c>'9') (c=='-' && (t=-1));
	do s=s*10+c-'0'; while ((c=getchar())>='0' && c<='9'); return s*t;
}

int c[max_size];
int lowbit ( int x ) {
    return x & -x ;
}
int sum ( int x ){
    int ret = 0;
    while ( x > 0 ){
        ret += c[x] ; x -= lowbit(x) ;
    }
    return ret;
}
void add ( int x , int d ) {
    while ( x < 1000005 ){
        c[x] += d ; x += lowbit(x);
    }
}

struct Node {
    int x , y , d;
    bool operator < ( const Node & rhs ) const {
        return x < rhs.x;
    }
}Node[max_size<<1];
struct vline {
    int x , l , r;
    bool operator < ( const vline &rhs ) const {
        return x < rhs.x;
    }
}vline[max_size<<1];

int n , m  ;
LL ans = 1;
int main ()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ )
    {
        int y , l , r;
        cin >> y >> l >> r;
        if ( l == 0 && r == 1000000 ) ans++;
        Node[2*i-1] = { l , y , 1 };
        Node[2*i] = { r+1 , y , -1 };
    }

    for ( int i = 1 ; i <= m ; i++ )
    {
        int x , l , r;
        cin >> x >> l >> r;
        if ( l == 0 && r == 1000000 ) ans++;
        vline[i] = { x , l , r };
    }

    sort ( Node+1 , Node+2*n+1 );
    sort ( vline+1 , vline+1+m );

    for ( int j = 0 , i = 1 ; i <= m ; i++ )
    {
        while ( j < 2*n && Node[j+1].x <= vline[i].x )
        {
            j++;
            add ( Node[j].y + 1 , Node[j].d );//平行线比垂直线左的点插入到树状数组当中，这些线的y坐标会对竖直线的答案产生影响
        }
        ans += sum ( vline[i].r + 1 ) - sum ( vline[i].l );
    }
    cout << ans << endl;
    return 0;
}