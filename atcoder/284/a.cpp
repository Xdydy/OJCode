#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

string s[15];

int main () {
    int n ; cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) cin >> s[i];
    for ( int i = n ; i >= 1 ; i-- ) {
        cout << s[i] << endl;
    }
}