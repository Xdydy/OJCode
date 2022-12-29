#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, k;
ll a[maxn];
ll b[maxn];
ll ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n >> k;
        ll sum = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        priority_queue<pair<ll,int> > pq;
        for ( int i = 1 ; i <= n ; i++ ) {
            sum += a[i];
            b[i] = a[i] - (n-i);
            pq.push({b[i], i});
        }

        ll res = 0 ;
        ll cnt = 0 ;
        while (k--)
        {
            auto top = pq.top();
            pq.pop();
            if ( top.first + cnt < 0 ) break;
            res += top.first + cnt;
            cnt++;
        }
        ans[cas] = sum - res;

    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}