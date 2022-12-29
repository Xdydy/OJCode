#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
ll ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        string s;
        cin >> s;
        string t;
        cin >> t;
        n = s.length();
        if ( t.length() == 1 ) {
            if ( t[0] == 'a' ) {
                ans[cas] = 1;
            }
            else {
                ans[cas] = 1ll << n;
            }
        }
        else {
            bool hasA = false;
            for ( int i = 0 ; i < t.length() ; i++ ) {
                if ( t[i] == 'a'  ) {
                    hasA = 1;
                    break;
                }
            }
            if ( hasA)  {
                ans[cas] = -1;
            }
            else {
                ans[cas] = 1ll << n;
            }
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}