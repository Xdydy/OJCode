#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
int ans[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        string s;
        cin >> s;
        s = ' ' + s;
        int posl = -1;
        int posr = -1;
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( s[i] == 'L' ) {
                posl = max(posl,i);
            }
        }
        for ( int i = n ; i >= 1 ; i-- ) {
            if ( s[i] == 'R' ) {
                posr = i;
            }
        }
        if ( posl == -1 || posr == -1 ) {
            ans[cas] = -1;
        } else if ( posr < posl ) {
            ans[cas] = 0;
        } else {
            ans[cas] = posl;
        }
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i] << endl;
}