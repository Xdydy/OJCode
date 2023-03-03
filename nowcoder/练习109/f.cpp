#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
vector<int> v[maxn];

int main () {
    IOS;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    for ( int i = 1;  i <= n ; i++ ) {
        v[a[i]].push_back(i);
    }
    int maxx = 1;
    for ( int i = 1 ; i <= n ; i++ ) {
        int cnt = 1;
        int cur = 1;
        int pos = lower_bound(v[a[i]+cur].begin(), v[a[i]+cur].end(), i) - v[a[i]+cur].begin();
        while(pos != v[a[i]+cur].size() ) {
            cnt++;
            if ( cur > 0 ) {
                cur = -cur;
            } else {
                cur = -cur;
                cur++;
            }
            pos = lower_bound(v[a[i]+cur].begin(), v[a[i]+cur].end(), i) - v[a[i]+cur].begin();
        }
        maxx = max(maxx,cnt);
    }
    cout << maxx << endl;
}