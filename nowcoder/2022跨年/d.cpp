#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int a,b,c;
int main () {
    cin >> a >> b >> c;
    if ( c == 1 ) {
        cout << "NO" << endl;
        return 0;
    }
    while(c % a==0) {
        c /= a;
    }
    while(c % b==0 ) {
        c /= b;
    }
    if (c == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}