#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

ll a,b,n,m;
ll ans[maxn];


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> a >> b ;
        cin >> n >> m;
        ll cnt1 = n / (m+1);
        ll cnt2 = n % (m+1);
        ans[cas] = cnt1*min(a*m,b*(m+1)) + cnt2*min(a,b);


    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}