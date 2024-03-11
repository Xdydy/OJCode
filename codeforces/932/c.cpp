#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int ans[maxn];
ll l;
struct node {
    ll a, b;
    bool operator<(const node &o) const { return b < o.b; }
} Node[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n >> l;
        for (int i = 1; i <= n; i++) {
            cin >> Node[i].a >> Node[i].b;
        }
        sort(Node + 1, Node + 1 + n);
        int maxx = 0;
        for (int i = 1; i <= n; i++) {
            priority_queue<ll> amax;
            ll sum = 0;
            for (int j = i; j <= n; j++) {
                amax.push(Node[j].a);
                sum += Node[j].a;
                while(amax.size() && Node[j].b - Node[i].b + sum > l) {
                    ll top = amax.top();
                    amax.pop();
                    sum -= top;
                }
                maxx = max(maxx, (int)amax.size());
            }   
        }
        ans[cas] = maxx;
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i] << endl;
}