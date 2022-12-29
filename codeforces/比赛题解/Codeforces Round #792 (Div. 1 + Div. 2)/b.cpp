#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

ll a , b , c;
ll ans1[maxn];
ll ans2[maxn];
ll ans3[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> a >> b >> c;
        ans3[cas] = c;
        ans2[cas] = b;
        ll res = c - a;
        ll cnt = res / b ;

        ans1[cas] = (cnt+1)*b + a;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << endl;
}