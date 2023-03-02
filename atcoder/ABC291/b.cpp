#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int  n;
double a[maxn];

int main() {
    cin >> n ;
    for( int i = 1 ; i <= 5*n ; i++ ) {
        cin >> a[i];
    }
    sort(a+1, a+1+5*n);
    double res = 0 ;
    for ( int i = n+1 ; i <= 4*n ; i++ ) {
        res += a[i];
    }
    res /= 1.0*(3*n);
    cout << fixed << setprecision(6) << res << endl;
}