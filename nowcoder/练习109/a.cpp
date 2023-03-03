#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

ll n;
int ans[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        int res = n % 2 + 2;
        if ( n <= 1 ) {
            res = n;
        } 
        ans[cas] = res;
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i] << "\n";
}