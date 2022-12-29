#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(3e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
bool ans[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        string s ; cin >> s;
        bool m = 0 , i = 0 , u = 0 , r = 0 , t = 0 ;
        for ( auto x : s ) {
            if ( x == 'm' ) {
                m = 1;
            }
            else if ( x == 'i' ) {
                i = 1;
            }
            else if ( x == 'u' ) {
                u =  1;
            }
            else if ( x == 'r' ) {
                r = 1;
            }
            else if ( x == 'T' ) {
                t = 1;
            }
        }
        ans[cas] = m&i&u&r&t&(n==5);
    }
    for (int i = 1; i <= T; i++)
        if (ans[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
}