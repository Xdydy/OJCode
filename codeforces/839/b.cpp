#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int a[5][5];
void rotate() {
    int tmp = a[1][1];
    a[1][1] = a[2][1];
    a[2][1] = a[2][2];
    a[2][2] = a[1][2];
    a[1][2] = tmp;
}
bool judge() {
    if ( a[1][1] < a[1][2] && a[2][1] < a[2][2] && a[1][1] < a[2][1] && a[1][2] < a[2][2] ) {
        return 1;
    }
    return 0;
}

bool ans[maxn];

int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) {
        cin >> a[1][1] >> a[1][2];
        cin >> a[2][1] >> a[2][2];
        bool flag = 0 ;
        if ( judge() ) {
            ans[cas] = 1;
        } else {
            for ( int i = 0 ; i <= 3 ; i++ ) {
                rotate();
                if (judge()) {
                    flag = 1;
                    break;
                }
            }
            ans[cas] = flag;
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}