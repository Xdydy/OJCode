#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
void solve() {
    cin >> n ;
    if (n%2==0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        int cur = 1+2*n-n/2;
        int l = 1 , r = cur-l;
        while(l<r) {
            cout << l << " " << r << endl;
            l += 2;
            r --;
        }
        l = 2 , r = 2*n;
        while(r>cur-1) {
            cout << l << " " << r << endl;
            l += 2;
            r -- ;
        }
        
    }
}

int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        solve();
    }
}