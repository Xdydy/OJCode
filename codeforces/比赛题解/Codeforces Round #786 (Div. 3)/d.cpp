#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
int b[maxn];
bool ans[maxn];

bool check() {
    bool flag = 1;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( a[i] != b[i] ) {
            flag = 0;
            break;
        }
    }
    return flag;
}


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];

        memcpy(b, a, (n+5)*sizeof(int));
        sort(b+1, b+1+n);
        bool res = 1;
        if ( n % 2 == 0 ) {
            for ( int i = 1 ; i <= n ; i+=2 ) {
                if ( a[i] > a[i+1] ) 
                    swap(a[i], a[i+1]);
            }
            ans[cas] = check();
        }
        else {
            for ( int i = 2 ; i <= n ; i+=2 ) {
                if ( a[i] > a[i+1] ) {
                    swap(a[i], a[i+1]);
                }
            }
            ans[cas] = check();
        }
        
        
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}