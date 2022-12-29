#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int n,x;
int a[maxn];
int ans[maxn];


int main ()
{
    IOS;
    cin >> n >> x;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( a[i] == x ) {
            cout << i << endl;
            break;
        }
    }
}