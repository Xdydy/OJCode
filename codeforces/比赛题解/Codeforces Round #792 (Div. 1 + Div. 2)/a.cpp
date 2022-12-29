#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

ll n;
int a[maxn];
int ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        vector<int> v;
        while(n) {
            v.push_back(n%10);
            n /= 10;
        }
        int minx = 10;
        reverse(v.begin(), v.end());
        for (int x : v) {
            minx = min(minx, x);
        }

        if ( v.size() > 2 ) {
            ans[cas] = minx;
        }
        else {
            ans[cas] = v[1];
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}