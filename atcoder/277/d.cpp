#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m;
int a[maxn];

int main() {
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);
    ll maxx = 0;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        int val = a[i];
        while (i <= n && (a[i] == val || a[i] == val + 1)) {
            sum += a[i];
            if (a[i] == val + 1) {
                val++;
            }
            i++;
        }
        i--;
        maxx = max(maxx, sum);
    }

    if (a[1] == 0 && a[n] == m - 1) {
        ll sum = 0;
        bool flag = 0;
        for (int i = 1; i <= n; i++) {
            int val = a[i];
            while (i <= n && (a[i] == val || a[i] == val + 1)) {
                sum += a[i];
                if (a[i] == val + 1) {
                    val++;
                }
                i++;
            }
            i--;
            if (i == n) {
                flag = 1;
            }
            break;
        }
        if (!flag) {
            for (int i = n; i >= 1; i--) {
                int val = a[i];
                while (i >= 1 && (a[i] == val || a[i] == val - 1)) {
                    sum += a[i];
                    if (a[i] == val - 1) {
                        val--;
                    }
                    i--;
                }
                i++;
                break;
            }
        }

        maxx = max(maxx, sum);
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += a[i];
    cout << sum - maxx << endl;
}
