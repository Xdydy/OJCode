#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        set<string> mp[4];
        for ( int i = 1 ; i <= 3 ; i++ ) {
            for ( int j = 1 ; j <= n ; j++ ) {
                string s ; cin >> s;
                mp[i].insert(s);
            }
        }

        int ans[4] = {0};
        for ( int i = 1 ; i <= 3 ; i++ ) {
            for ( auto x : mp[i] ) {
                int cnt = 0;
                for ( int j = 1 ; j <= 3 ; j++ ) {
                    if ( mp[j].find(x) != mp[j].end() ) {
                        cnt++;
                    }
                }
                if ( cnt == 1 ) {
                    ans[i] += 3;
                }
                else if ( cnt == 2 ) {
                    ans[i] += 1;
                }
            }
        }
        cout << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
    }
}