#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


void solve() {
    int x,y;
    cin >> x >> y;
    deque<int> ans;
    ans.push_back(x);
    int cur = x;
    cur--;
    while(cur > y) {
        ans.push_back(cur);
        cur--;
    }
    while(cur < x) {
        ans.push_back(cur);
        cur++;
    }
    cout << ans.size() << endl;
    for ( auto x : ans ) {
        cout << x << " " ;
    }
    cout << endl;
}

int main () {
    IOS;
    int T ; cin >> T;
    while(T--) {
        solve();
    }
}