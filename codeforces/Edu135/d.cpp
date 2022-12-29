#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
string s;
bool ans[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> s;
        deque<char> q;
        for (auto x : s) {
            q.push_back(x);
        }

        bool res = 0;
        while (q.size()) {
            if (q.size() == 2) {
                if (q.front() != q.back()) {
                    res = 1;
                } else {
                    res = 0;
                }
                q.pop_front();
                q.pop_back();
            } else if (q.front() == q.back()) {
                q.pop_front();
                q.pop_back();
            } else {
                int sz = q.size();
                int cnt1 = 0 , cnt2 = 0;
                char ch1 = q.front();
                char ch2 = q.back();
                for ( int i = 0 ; i < sz ; i++ ) {
                    if ( ch1 == q[i] ) {
                        cnt1++;
                    }
                    else break;
                }
                for ( int i = sz-1;  i >= 0 ; i-- ) {
                    if ( ch2 == q[i] ) {
                        cnt2++;
                    }
                    else break;
                }
                if ( cnt1 % 2 == 0 && cnt2 % 2 == 0 ) {
                    while(cnt1--) {
                        q.pop_front();
                    }
                    while(cnt2--) {
                        q.pop_back();
                    }
                }
                else {
                    res  =1;
                    break;
                }
            }
        }
        ans[cas] = res;
    }
    for (int i = 1; i <= T; i++)
        if (ans[i])
            cout << "Alice" << endl;
        else
            cout << "Draw" << endl;
}