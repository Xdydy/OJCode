#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
string s;
int pre[maxn];
int ans[maxn];
void solve() {
    cin >> n;
    cin >> s;
    s = ' ' + s;
    memset(pre, 0, sizeof(int)*(n+5));
    pre[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        int x = s[i] - '0';
        if (x) {
            ans[i] = (i-1)-pre[i-1];
        } else {
            ans[i] = pre[i-1];
        }
        pre[i] = pre[i-1] + x;   
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main () {
    int T ; cin >> T;
    while(T--) {
        solve();
    }
}