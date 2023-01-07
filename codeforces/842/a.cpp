#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
int ans[maxn];


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        ll k ; cin >> k;
        ans[cas] = k-1;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}