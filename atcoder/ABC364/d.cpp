#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,q;
int a[maxn];
int ans[maxn];

bool judge(int mid, int pos, int b, int k) {
    int pos1 = upper_bound(a+1,a+1+n, b+mid) - a - 1;
    int sum1 = pos1 - pos;
    int pos2 = lower_bound(a+1,a+1+n, b-mid) - a;
    int sum2 = pos - pos2 + 1;
    int sum = sum1 + sum2;
    return sum >= k;
}

int solve(int b, int k) {
    int pos = lower_bound(a+1,a+1+n,b) -a;
    int l = 0, r = 1e9;
    while(l < r) {
        int mid = l + r >> 1;
        if (judge(mid, pos, b, k)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    return l;
}

int main () {
    IOS;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    a[n+1] = 1e9+7;
    for (int i = 1; i <= q; i++) {
        int b, k;
        cin >> b >> k;
        ans[i] = solve(b,k);
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }
}