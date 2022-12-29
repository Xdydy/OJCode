#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
int cnt[maxn];
int ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];

        sort(a+1, a+1+n);
        memset(cnt, 0, sizeof(int)*(n+5));
        vector<int> v;
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( v.empty() || v.back() != a[i] ) {
                v.push_back(a[i]);
            }
        }        

        for ( int i = 1 ; i <= n ; i++ ) {
            a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        }
        for ( int i = 1 ; i <= n ; i++  ) {
            cnt[a[i]]++;
            if ( cnt[a[i]] > 2 )
                cnt[a[i]] = 2;
        }

        int res = 0;
        for ( int i = 1 ; i <= v.size() ; i++ ) {
            res += cnt[i];
        }
        ans[cas] = (res + 1 ) / 2 ;

    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}