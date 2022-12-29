#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(2e5 + 10)
#define MAX (int)(1e5+7)

int n , q;
LL c[max_size] , fac[max_size];
int lowbit ( int x ) {
    return x & (-x);
}
LL query ( int x ) {
    LL res = 0 ;
    while (x) {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
void add ( int x , int k ) {
    while ( x <= n ) {
        c[x] += k;
        x += lowbit(x);
    }
}

int v[20] , a[20] , p[max_size];
void upd ( LL sum ) {
    for ( int i = 1 ; i <= 15 ; i++ ) v[i] = 1;
    LL tmp = sum;
    for ( int i = 1 ; i <= 15 ; i++ )
    {
        int t = tmp / fac[15-i];
        int cnt = 0 ;
        for ( int j = 1 ; j <= 15 ; j++ )
        {
            if ( v[j] )
            {
                if ( cnt == t )
                {
                    a[i] = j;
                    v[j] = 0 ;
                    break;
                }
                ++cnt;
            }
        }
        tmp %= fac[15-i];
    }
    if ( n < 15 )
    {
        int d = 15 - n;
        for ( int i = 1  ; i <= n ; i++ )
        {
            add ( i , -p[i] );
            p[i] = a[i+d] - d;
            add ( i , p[i] );
        }
    }
    else
    {
        int d = n - 15 ;
        for ( int i = n-14 ; i <= n ; i++ )
        {
            add ( i , -p[i] );
            p[i] = a[15-(n-i)] + d;
            add ( i , p[i] );
        }
    }
}

vector <LL> ans;
int main ()
{
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for ( int i = 1 ; i <= n ; i++ ) add(i,i);
    for ( int i = 1 ; i <= n ; i++ ) p[i] = i ;
    fac[0] = 1;
    for ( int i = 1 ; i <= 15 ; i++ ) fac[i] = fac[i-1] *  i;   
    
    LL res = 0 ; 
    for ( int i = 1  ; i <= q ; i++ )
    {
        int op ; cin >> op;
        if ( op == 1 )
        {
            int l , r;
            cin >> l >> r;
            ans.push_back(query(r)-query(l-1));
        }
        else
        {
            int x ; cin >> x;
            res += x;
            upd (res);
        }
    }
    for ( auto x : ans )
        cout << x << endl;
}