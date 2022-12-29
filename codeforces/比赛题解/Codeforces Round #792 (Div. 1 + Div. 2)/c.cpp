#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m;
vector<int> a[maxn];
int b[maxn];
pair<int,int> res[maxn];
pair<int,int> ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n >> m;
        for ( int i = 1 ; i <= n ; i++ ) {
            a[i].clear();
            a[i].push_back(0);
            for ( int j = 1 ; j <= m ; j++ ) {
                int x ; cin >> x;
                a[i].push_back(x);
            }
        }
        bool flag = 1;
        for ( int i = 1 ; i <= n ; i++ ) {
            for (int j = 1 ; j <= m ; j++ ) {
                b[j] = a[i][j];
            }
            sort(b+1, b+1+m);
            pair<int,int> v = {-1,-1};
            for ( int j = 1 ; j <= m ; j++ ) {
                if ( b[j] != a[i][j] ) {
                    if ( v.first == -1 ) {
                        v.first = j;
                    }
                    else if ( v.second == -1 ) {
                        v.second = j;
                    }
                    else {
                        flag = 0;
                        break;
                    }
                }
            }
            if (!flag) break;
            res[i] = v;
        }
        if (!flag) {
            ans[cas] = {-1,-1};
        }
        else {
            int pos = -1;
            for ( int i = 1 ; i <= n ; i++ ) {
                if ( res[i].first != -1 ) {
                    pos = i;
                    break;
                }
            }
            if ( pos == -1 ) {
                ans[cas] = {1,1};
            }
            else {
                flag = 1;
                for ( int i = 1 ; i <= n ; i++ ) {
                    if ( res[i].first == -1 ) {
                        if ( a[i][res[pos].first] != a[i][res[pos].second] ) {
                            flag = 0;
                            break;
                        }
                    }
                    else {
                        if ( res[i].first != res[pos].first || res[i].second != res[pos].second ) {
                            flag = 0 ;
                            break;
                        }
                    }
                }
                if (!flag) ans[cas] = {-1,-1};
                else ans[cas] = res[pos];
            }
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i].first == -1 ) cout << -1 << endl;
        else cout << ans[i].first << " " << ans[i].second << endl;
}