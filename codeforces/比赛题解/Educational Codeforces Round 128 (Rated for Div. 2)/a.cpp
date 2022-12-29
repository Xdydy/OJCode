#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
int ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        int l1 , r1;
        int l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if ( r1 >= l2 && r2 >= l1 ) {
            ans[cas] = max(l1, l2);
        }
        else {
            ans[cas] = l1 + l2;
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}