#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(2e5+10)

struct node {
	int x , t , y;
	bool operator < ( const node& rhs ) const {
		return x < rhs.x;
	}
}Node[max_size] , tmp[max_size];
int n;
int tree[max_size] , tp1[max_size] , tp2[max_size] , tp3[max_size];
int lowbit ( int x ) { return x&-x; }
void add ( int x , int i ){
	while ( x <= n ) {
		tree[x] += i;
		x += lowbit(x);
	}
}
int sum ( int x ) {
	int ret = 0;
	while ( x > 0 ) {
		ret += tree[x] ; x -= lowbit(x);
	}
	return ret;
}

LL cdq ( int L , int R ) {
	if ( L >= R ) return 0;
	LL ans = 0;
	int mid = L + R >> 1;
	int s1 = L , s2 = mid+1;
	for ( int i = L ; i <= R ; i++ )
	{
		if ( Node[i].t <= mid )
			tmp[s1++] = Node[i];
		else tmp[s2++] = Node[i];
	}
	for ( int i = L ; i <= R ; i++ )
		Node[i] = tmp[i];
	s1 = L;
	for ( int i = mid+1 ; i <= R ; i++ )
	{
		for ( ; s1 <= mid && Node[s1].x < Node[i].x ; s1++ ) add(Node[s1].y,1);
		ans += sum ( Node[i].y-1 );
	}
	for ( int i = s1-1 ; i >= L ; i-- )
		add(Node[i].y,-1);
	return ans = ans + cdq(L,mid) + cdq(mid+1,R);
}

int main ()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ )
	{
		int x ;
		cin >> x;
		tp1[x] = i;
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
		int x ;
		cin >> x;
		tp2[x] = i;
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
		int x ;
		cin >> x;
		tp3[x] = i;
	}
	for ( int i = 1 ; i <= n ; i++ )
		Node[i] = { tp1[i] , tp2[i] , tp3[i] };
	sort ( Node+1 , Node+1+n );
	cout << cdq(1,n) << endl;
}