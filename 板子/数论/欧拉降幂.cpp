#include<bits/stdc++.h>
using namespace std;
#define max_size 1000050
#define LL long long 

int tot;
int phi[max_size];
int pri[max_size];
bool mark[max_size];
void get_phi()
{
	phi[1] = 1;
	for ( int i = 2 ; i < max_size ; i++ )
	{
		if (!mark[i]){
			pri[++tot] = i;
			phi[i] = i-1;
		}
		for ( int j = 1 ; j <= tot && i*pri[j] < max_size ; j++ )
		{
			mark[i*pri[j]] = 1;
			if( i % pri[j] == 0 ){
				phi[i*pri[j]] = phi[i] * pri[j];
				break;
			}
			else 
				phi[i*pri[j]] = phi[i] * ( pri[j] - 1 );
		}
	}
}

LL quickpow( LL x, LL y, LL m )
{
    LL cur = x,ret = 1ll;
    for(int i=0; y; i++)
    {
        if(y&(1ll<<i)) {y-=(1ll<<i); ret = ret*cur;}
		if ( ret > m ) ret = ret % m + m ;
        cur = cur*cur;
		if ( cur > m ) cur = cur % m + m;
    }
    return ret;
}
LL a[max_size];
LL ans[max_size] , cnt = 0;
LL solve( LL l , LL r , LL m  )
{
	if ( m == 1 )
		return 1;
	if ( l == r-1 )
	{
		if ( a[r] < phi[m] )
			return quickpow(a[l],a[r],m);
		if ( a[r] >= phi[m] )
			return quickpow(a[l],a[r]%phi[m]+phi[m],m);	
	}
	LL tmp = solve( l+1 , r , phi[m] );
	if ( tmp < phi[m] )
		return quickpow(a[l],tmp,m);
	if ( tmp >= phi[m] )
		return quickpow(a[l],tmp%phi[m]+phi[m],m);

}
int main ()
{
	get_phi();
	LL n , q;
	cin >> n >> q;
	for ( int i = 1 ; i <= n ; i++ )
		scanf( "%lld",&a[i] );
	for ( int i = 1 ; i <= q ; i++ )
	{
		LL l , r , m;
        cin >> l >> r >> m;
		LL res = solve(l,r,m) % m ;
		ans[cnt++] = res;
	}
	for ( int i = 0 ; i < cnt ; i++ )
		printf("%lld\n",ans[i]);
}