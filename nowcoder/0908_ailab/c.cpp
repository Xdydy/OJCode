#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

bool ans[maxn];
string s;
int n;


int main () {
    int T ; cin >> T;
    for (int cas = 1 ; cas <= T; cas++) {
        cin >> n;
        cin >> s;
        s = ' ' + s;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            int ch = s[i];
            int cnt0 = 0, cnt1 = 0;
            while(i <= n && s[i] != '#') {
                if (s[i] == '0') {
                    cnt0++;
                } else {
                    cnt1++;
                }
                i++;
            }
            v.push_back(min(cnt0, cnt1));
        }   
        int flag = 0;
        for (auto x : v) {
            if (x & 1) {
                flag ^= 1;
            }
        }
        ans[cas] = flag;
    }
    for (int i = 1; i <= T; i++) {
        if (ans[i]) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
}