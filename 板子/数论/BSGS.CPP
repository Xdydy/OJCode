#include <bits/stdc++.h>
using namespace std;
#define max_size 1000050


int BSGSEX ( int a , int b , int c )
{
	if ( b == 1 )
		return 0;
	int cnt = 0;
	long long base = 1;
	for ( int g = gcd(a,c) ; g != 1 ; g = gcd(a,c) )
	{
		if (b%g) return -1;
		b /= g;
		c /= g;
		base = base * ( a / g ) % c;
		cnt++;
		if ( b == base ) return cnt;
	}
	int thres = ceil(sqrt(c));
	unordered_map<int , int> table;
	long long mul = 1;
	for ( int i = 0 ; i < thres ; i++ , mul = mul*a%c )
		table[mul*b%c] = i;
	
	long long a_t = base * mul % c;
	for ( int i = 1 ; i <= thres+1  ; i++ , a_t = a_t * mul % c )
		if ( table.count(a_t) )
			return i * thres - table[a_t] + cnt;
	return -1;
}

int main ()
{
	int T;
	cin >> T;
	vector <int> ans;
	while (T--)
	{
		int a , b , n;
		cin >> a >> b >> n;
		ans.push_back(BSGSEX(a,b,n));
	}
	for ( int i = 0 ;  i < ans.size() ; i++ )
		if  ( ans[i] == -1 )
			cout << "QAQ" << endl;
		else cout << ans[i] << endl;
}