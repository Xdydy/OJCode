#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
int p[maxn];
int q[maxn];
int vis[maxn];
vector<int> v[maxn];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    memset(vis,0,sizeof(int)*(n+5));
    for ( int i = 1 ; i <= n ; i++ ) v[i].clear();
    bool flag = 1;
    for ( int i = 1 ; i <= n ; i++ ) {
        vis[a[i]]++;
        v[a[i]].push_back(i);
        if ( vis[a[i]] > 2 ) {
            flag = 0 ;
            break;
        }
    }
    if (!flag) {
        cout << "NO" << endl;
    } else {
        set<int,greater<int>> st;
        for ( int i = 1 ; i <= n ; i++ ) {
            if (!vis[i]) {
                st.insert(i);
            }
        }
        for ( int i = 1 ; i <= n ; i++ ) {
            p[i] = q[i] = a[i];
        }
        for ( int i = n ; i >= 1 ; i-- ) {
            if (vis[i] == 2) {
                int pos1 = v[i][0];
                int pos2 = v[i][1];
                if (st.empty()) {
                    flag = 0 ;
                    break;
                }
                int x = *st.begin();
                st.erase(x);
                if ( x > i ) {
                    flag = 0 ;
                    break;
                }
                p[pos1] = q[pos2] = x;
            }
        }
        if (!flag)  {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for ( int i = 1 ; i <= n ; i++ ) {
                cout << p[i] << " ";
            }
            cout << endl;
            for ( int i = 1 ; i <= n ; i++ ) {
                cout << q[i] << " ";
            }
            cout << endl;
        }
    }

}

int main() {
    IOS;
    // FFF;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}