#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
int vis[maxn];

int main () {
    IOS;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    for ( int i = 1;  i <= n ; i++ ) {
        vis[a[i]]++;
    }
    int c1 = 0 ;
    int c2 = 0 ;
    int c3 = 0 ;
    for ( int i = 0 ; i <= 1e5 ; i++ ) {
        if ( !vis[i] ) continue;
        else if ( vis[i] ==1 )  {
            c1++;
        } else if ( vis[i] == 2 ) {
            c2++;
        } else if ( vis[i] >= 3 ) {
            c3++;
        }
    }

    if ( c1 % 2 == 0 ) {
        cout << "YES" << endl;
    } else {
        if ( c3 > 0 ) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}