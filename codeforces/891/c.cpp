#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int b[maxn];
int a[maxn];
void solve() {
    cin >> n ;
    int n2 = n*(n-1)/2;
    for ( int i = 1 ; i <= n2 ; i++ ) cin >> b[i];
    sort(b+1,b+1+n2);

    int pos = 1;
    for ( int i = 1; i < n; i++ ) {
        a[i] = b[pos];    
        int cnt = n-i;
        pos += cnt;
    }
    a[n] = a[n-1];
    for ( int i = 1 ; i <= n ; i++ ) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main ()  {
    IOS;
    int T ; cin >> T;
    while(T--) {
        solve();
    }
}