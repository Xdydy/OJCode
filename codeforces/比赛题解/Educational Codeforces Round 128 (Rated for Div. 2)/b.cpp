#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m;
char a[10][10];
bool ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n >> m;
        for ( int i = 1 ; i <= n ; i++ ) {
            cin >> a[i] + 1;
        }
        int minup = n+1;
        int minleft = m+1;
        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = 1 ; j <= m ; j++ ) {
                if ( a[i][j] == 'E' ) continue;
                minup = min(minup, i);
                minleft = min(minleft, j);
            }
        }   
        bool flag = 0;

        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = 1 ; j <= m ; j++ ) {
                if ( a[i][j] == 'R' ){
                    int up = i-1;
                    int left = j-1;
                    if ( minup - up >= 1 && minleft - left >= 1 ) {
                        flag = 1;
                        break;
                    }
                }
            }
            if ( flag ) break;
        }
        ans[cas] = flag;
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}