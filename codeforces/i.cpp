#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int x , y , t;
int ans[105];
int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> x >> y >> t;
        string s ;
        cin >> s;
        s = ' ' + s;
        if ( x == 0 && y == 0 ) {
            ans[cas] =  0;
            continue;
        }
        int res = -1 ;
        for ( int i = 1 ; i <= t ; i++ ) {
            if ( s[i] == 'L' ) {
                if ( x < 0 ) x++;
            }
            else if ( s[i] == 'R' ) {
                if ( x > 0 ) x--;
            }
            else if ( s[i] == 'U' ) {
                if ( y > 0 ) y--;
            }
            else if ( s[i] == 'D' ) {
                if ( y < 0 ) y++;
            }

            if ( x == 0 && y == 0 ) {
                res = i;
                break;
            }
            
        }

        ans[cas] = res;        

    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}