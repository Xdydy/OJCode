#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
LL a[maxn];
LL ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        sort(a+1, a+1+n);
        ans[cas] = a[n] + a[n-1];
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}