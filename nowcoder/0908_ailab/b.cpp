#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

string s;
string ans[2005];

int main () {
    int T ; cin >> T;
    set<int> ps;
    for (int i = 1; i <= 500; i++) {
        int x = i;
        int cnt = 0 ;
        while(x) {
            if (x & 1) {
                cnt++;
            }
            x >>= 1;
        }
        if (cnt & 1) {
            ps.insert(i);
        }
    }
    for (int cas = 1; cas <= T; cas++) {
        cin >> s;
        int len = s.length();
        for (auto x : ps) {
            if (x > len) {
                break;
            }
            s[x-1] = s[x-1] - 'a' + 'A';
        }
        ans[cas] = s;
    }
    for (int i = 1; i <= T; i++) {
        cout << ans[i] << endl;
    }
}