#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
bool ans[maxn];


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];

        bool flag = 0;
        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = i+1; j <= n ; j++ ) {
                if ( __gcd(a[i],a[j]) <= 2 ) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        ans[cas] = flag;
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "Yes" << endl;
        else cout << "No" << endl;
}