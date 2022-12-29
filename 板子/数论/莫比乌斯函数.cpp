#include<bits/stdc++.h>
using namespace std;
#define max_size 1000090


long long prime[max_size];
long long check[max_size] = {0};
int tot = 0;
void init(){
	for ( int i = 2 ; i < 2000005 ; i++ ){
		if ( !check[i] )
			prime[tot++] = i;
		for ( int j = 0 ; j < tot ; j++ )
		{
			if ( i * prime[j] > 2000005 )
				break;
			check[i*prime[j]] = 1;
			if ( i % prime[j] == 0 )
				break;
		}
	}
}
int main ()
{
	int T;
	cin >> T;
	init();
	
	while ( T-- )
	{
		long long n;
		cin >> n;
		if ( n == 1 ) 
		{
			cout << "1" << endl;
			continue;
		}
		long long m = sqrt(n) + 0.5;
		long long cnt = 0;
		bool flag = true;
		for ( int i = 0 ; prime[i]*prime[i] <= n ; i++ )
		{
			if ( n % prime[i] != 0 ) continue;
			n /= prime[i];
			if ( n % prime[i] == 0 )
			{
				flag = false;
				break;
			}
			cnt++;
		}
		if ( n > 1 ) cnt++;
		if ( flag == false )
			cout << "0" << endl;
		else 
			if ( cnt % 2 == 1 )
				cout << "-1" << endl;
			else cout << "1" << endl;
	}
	return 0;
}
