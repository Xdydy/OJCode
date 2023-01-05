#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m;
ll a[maxn];
int ans[maxn];

int res = 0;
void putLast() {
    ll cur = 0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for (int i = m + 1; i <= n; i++) {
        if (a[i] < 0) {
            pq.push(a[i]);
        }
        cur += a[i];
        while (cur < 0) {
            if (pq.size()) {
                ll top = pq.top();
                pq.pop();
                cur -= top ;
                top *= -1;
                cur += top;
                res++;
            }
        }
    }
}
void putFirst() {
    ll cur = 0;
    priority_queue<ll> pq;
    for (int i = m; i > 1; i--) {
        if (a[i] > 0) {
            pq.push(a[i]);
        }
        cur += a[i];
        while (cur > 0) {
            if (pq.size()) {
                ll top = pq.top();
                pq.pop();
                cur -= top ;
                top *= -1;
                cur += top;
                res++;
            }
        }
    }
}

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        res = 0;
        putLast();
        putFirst();

        ans[cas] = res;
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i] << endl;
}