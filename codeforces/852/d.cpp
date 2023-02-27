#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn],pa[maxn];
int b[maxn],pb[maxn];

int main () {
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    for ( int i = 1 ; i <= n ; i++ ) cin >> b[i];

    for ( int i = 1 ; i <= n ; i++ ) {
        pa[a[i]] = i;
        pb[b[i]] = i;
    }
    ll last1 = pa[1];
    ll last2 = pb[1];
    ll l = min(last1,last2);
    ll r = max(last1,last2);
    ll res = 0 ;
    ll len = l-1;
    res += 1ll*(len+1)*len/2;
    len = r-l-1;
    res += 1ll*(len+1)*len/2;
    len = n-r;
    res += 1ll*(len+1)*len/2;

    pair<int,int> p1,p2;
    p1 = {last1,last1};
    p2 = {last2,last2};
    for ( int mex = 2 ; mex <= n ; mex++ ) {
        ll pos1 = pa[mex];
        ll pos2 = pb[mex];
        ll al1 = 1, al2 = p1.first;
        ll ar1 = p1.second , ar2 = n;
        ll bl1 = 1 , bl2 = p2.first;
        ll br1 = p2.second , br2 = n;
        if ( pos1 < p1.first ) {
            p1.first = pos1;
            al1 = pos1+1;
        }
        if ( pos1 > p1.second ) {
            p1.second = pos1;
            ar2 = pos1-1;
        }
        if ( pos2 < p2.first ) {
            p2.first = pos2;
            bl1 = pos2+1;
        }
        if ( pos2 > p2.second ) {
            p2.second = pos2;
            br2 = pos2-1;
        }
        if ( pos1 > p1.first && pos1 < p1.second ) continue;
        if ( pos2 > p2.first && pos2 < p2.second ) continue;
        if ( al1 > bl2 || bl1 > al2 ) continue;
        ll res1 = min(al2,bl2) - max(al1,bl1) + 1;

        if ( ar1 > br2 || br1 > ar2 ) continue;
        ll res2 = min(ar2,br2) - max(ar1,br1) + 1;
        res += 1ll*res1*res2;
    }
    res++;
    cout << res << endl;
}
 