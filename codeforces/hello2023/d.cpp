#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
int b[maxn];
int m;
int c[maxn];
int l[maxn], r[maxn];
multiset<int> xc;

bool ans[maxn];
bool judge() {
    for (int i = 1; i <= n; i++) {
        if (b[i] > a[i]) {
            return false;
        }
    }
    return true;
}

void getLR() {
    for (int i = 1; i <= n; i++)
        l[i] = r[i] = i;
    stack<pair<int, int>> st;
    for (int i = 1; i <= n; i++) {
        while (st.size() && b[i] > st.top().first) {
            int x = st.top().second;
            r[x] = i;
            st.pop();
        }
        st.push({b[i], i});
    }
    while(st.size()) {
        int x = st.top().second;
        r[x] = n ;
        st.pop();
    }
    for ( int i = n ; i >= 1 ; i-- ) {
        while(st.size() && b[i] > st.top().first ) {
            int x = st.top().second;
            l[x] = i;
            st.pop();
        }
        st.push({b[i],i});
    }
    while(st.size()) {
        int x = st.top().second;
        l[x] = 1;
        st.pop();
    }
}

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        cin >> m;
        xc.clear();
        for (int i = 1; i <= m; i++) {
            cin >> c[i];
            xc.insert(c[i]);
        }

        if (!judge()) {
            ans[cas] = 0;
        } else {
            getLR();
            bool flag = 1;
            map<int,int> mp;
            for ( int i = 1 ; i <= n ; i++ ) {
                if ( a[i] == b[i] ) continue;
                if ( mp.find(b[i]) != mp.end()  ) {
                    if ( mp[b[i]] >= i )
                        continue;
                }
                int rm = r[i];
                mp[b[i]] = rm;
                auto it = xc.find(b[i]);
                if ( it == xc.end() ) {
                    flag = 0;
                    break;
                } else {
                    xc.erase(it);
                }
            }
            ans[cas] = flag;
        }
    }
    for (int i = 1; i <= T; i++)
        if (ans[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
}