#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
ll c;
ll a[maxn];
int ans[maxn];

bool judge(ll x) {
    ll sum = 0;
    for ( int i = 1 ; i <= n ; i++ ) {
        ll s = a[i] + x*2;
        sum += s*s;
        if ( sum >= c ) return true;
    }
    
    return sum == c;
}

int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n >> c;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        ll left = 0, right = 1e9;
        while(left < right) {
            ll mid = left + right >> 1;
            if (judge(mid) ) {
                right = mid;
            } else {
                left = mid+1;
            }
        }   
        ans[cas] = left;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}