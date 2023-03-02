#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

string a,b;

void solve() {
    cin >> a;
    cin >> b ;
    int n = a.length();
    int m = b.length();
    a = '*' + a + '*';
    b = '*' + b + '*';
    bool flag = 0;
    string ans;
    for ( int i = 0 ; i <= n ; i++ ) {
        for ( int j = 0 ; j <= m ; j++ ) {
            if ( a[i] == b[j] && a[i+1] == b[j+1] ) {
                flag = 1;
                if ( a[i] == '*' ) {
                    ans += a[i+1];
                    ans += '*';
                }
                else if ( a[i+1] == '*' ) {
                    ans += '*';
                    ans += a[i];
                }
                else {
                    ans += '*';
                    ans += a[i];
                    ans += a[i+1];
                    ans += '*';
                }
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    if ( flag) {
        cout << "YES" << endl;
        cout << ans << endl;
    } else {
        cout << "NO\n";
    }
}
int main () {
    IOS;
    int T ; cin >> T;
    while(T--) {
        solve();
    }
}