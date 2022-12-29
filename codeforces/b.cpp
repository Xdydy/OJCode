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
        cin >> n;
        string s1 , s2;
        cin >> s1 >> s2;
        bool flag = 1;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( s1[i] == s2[i] ) continue;
            if ( s1[i] == 'G' ) {
                if ( s2[i] == 'B' ) {
                    continue;
                }
                else  {
                    flag = 0 ;
                    break;
                }
            } 
            else if ( s1[i] == 'B' ) {
                if ( s2[i] == 'G' ) {
                    continue;
                }
                else {
                    flag = 0;
                    break;
                }
            }
            else {
                flag = 0 ;
                break;
            }
        }
        ans[cas] = flag;
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}