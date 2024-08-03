#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
ll m;
ll a[maxn];

bool judge(ll mid) {
    ll sum = 0 ;
    for (int i = 1; i <= n; i++) {
        sum += min(mid, a[i]);
    }
    return sum <= m;
}

int main () {
    cin >> n;
    cin >> m;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }
    if (sum <= m) {
        cout << "infinite" << endl;
        return 0;
    }

    ll left = -1, right = m;
    while(left < right) {
        ll mid = left + right + 1 >> 1;
        if (judge(mid)) {
            left = mid;
        } else {
            right = mid-1;
        }
    }
    cout << left << endl;
}