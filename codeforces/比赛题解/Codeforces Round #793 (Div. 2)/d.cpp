#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n ;
string s;

void solve() {
    cout << "YES\n" ;
    deque<pair<int,int> > v;
    bool flag = 0;
    for ( int i = 1 ; i <= n ; i++ ) {
        v.push_back({s[i]-'0', i});
        if ( v.back().first == 0 ) {
            flag = 1;
        }
    }
    if (!flag) {
        for ( int i = 1;  i < v.size() ; i++ ) {
            cout << v.front().second << " " << v[i].second << endl;
        }
    }
    else {
        while(v.front().first == 0) {
            auto top = v.front();
            v.pop_front();
            v.push_back(top);
        }
        for ( int i = 1 ; i < v.size() ; i++ ) {
            if ( v[i].first == 0 ) {
                int j = i;
                while(i < v.size() && v[i].first == 0 ) {
                    cout << v[i-1].second << " " << v[i].second << endl;
                    i++;
                }
                v[j-1].second = v[i-1].second;
            }
        }
        for ( int i = 1 ; i < v.size() ; i++ ) {
            if ( v[i].first == 1 ) {
                cout << v.front().second << " " << v[i].second << endl;
            }
        }
    }
}

int main () {
    IOS;
    int T ; cin >> T;
    for (int cas = 1 ; cas <= T ; cas++ ) {
        cin >> n >> s;
        s = ' ' + s;
        int cnt = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            if (s[i] == '1' ){
                cnt++;
            }
        }
        if ( cnt & 1 || cnt == 0 ) {
            cout << "NO\n" ;
        }
        else {
            solve();
        }
    }
}