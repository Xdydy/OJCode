#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

string s;
int n ;
string ans[maxn];
int main () {
    IOS;
    int T ; cin >> T;

    for ( int cas = 1 ; cas <= T ; cas++ ) {
        cin >> s;
        n = s.length();
        s = '0' + s;
        int flag = 0;
        int pos = n+1;
        for ( int i = n ; i >= 0 ; i-- ) {
            int x = s[i] - '0';
            if ( x + flag >= 5 ) {
                flag = 1;
                pos = i ;
            } else {
                s[i] += flag;
                flag = 0 ;
            }
        }
        deque<char> res ;
        for ( int i = 0 ; i <= n ; i++ ) {
            res.push_back(s[i]);
        }
        for ( int i = pos ; i <= n ; i++ ) {
            res[i] = '0';
        }
        if (res.front() == '0' ) {
            res.pop_front();
        }
        for ( auto x : res ) {
            ans[cas].push_back(x);
        }
    }
    for ( int i = 1 ; i <= T ; i++ ) {
        cout << ans[i] << endl;
    }
}