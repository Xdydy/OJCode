#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int n;
int a[maxn];
int ans[maxn];


int main ()
{
	IOS;
	int T ; cin >> T;
	for ( int cas = 1 ; cas <= T ; cas++ )
	{
		cin >> n;
		string s;
		cin >> s;
		s = ' ' + s;
		vector<int> v0;
		for ( int i = 1 ; i <= n ; i++ )
		{
			if ( s[i] == '0' )
				v0.push_back(i);
		}
		int res = 0 ;
		for ( int i = 1 ; i < v0.size() ; i++ )
		{
			int len = v0[i] - v0[i-1];
			res += max(0, 3-len);
		}
		ans[cas] = res;
	}
	for ( int i = 1 ; i <= T ; i++ )
		cout << ans[i] << endl;
}