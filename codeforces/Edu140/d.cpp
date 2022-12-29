#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
string s;

int main () {
    cin >> n;
    cin >> s;
    int cnt1 = 0 , cnt0 = 0 ;
    for ( int i = 0 ; i < n ; i++ ) {
        if (s[i] == '1') {
            cnt1++;
        }
        else if ( s[i] == '0' ) {
            cnt0++;
        }
    }
    int l = 1 << cnt1 ;
    int r = (1<<n) - (1<<cnt0) + 1;
    for ( int i = l ; i <= r ; i++ ) {
        cout << i << " ";
    }
    cout << endl;
}