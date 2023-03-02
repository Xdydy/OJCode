#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
string s;
bool ans[maxn];


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        cin >> s;
        s = ' ' + s;
        int cnt = 0;
        for ( int l = 1 , r = n ; l <= n/2 ; l++,r-- ) {
            if ( s[l] == s[r] ) continue;
            cnt++;
            while(l <= n/2 && s[l] != s[r] ) {
                l++;
                r--;
            }
            l--;
            r++;
        }
        if ( cnt >= 2 ) {
            ans[cas] = 0 ;
        } else if ( cnt <= 1 ) {
            ans[cas] = 1;
        }

    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "Yes" << endl;
        else cout << "No" << endl;
}