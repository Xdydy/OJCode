#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[105];
int b[105];
int c[105];
int d[105];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i], c[i] = a[i];
        for ( int i = 1 ; i <= n ; i++ ) cin >> b[i], d[i] = b[i];

        multiset<pair<int,int> > st;
        for ( int i = 1 ; i <= n ; i++ ) {
            st.insert({a[i], b[i]});
        }

        sort(c+1, c+1+n);
        sort(d+1, d+1+n);

        bool flag = 1;
        for ( int i = 1 ; i <= n ; i++ ) {
            auto it = st.find({c[i], d[i]});
            if ( it == st.end() ) {
                flag = 0;
                break;
            }
            else{
                st.erase(it);
            }
        }

        if (!flag) {
            cout << "-1" << endl;
        }
        else {
            vector<pair<int,int> > ans;
            for ( int i = 1 ; i <= n ; i++ ) {
                if ( a[i] == c[i] && b[i] == d[i] ) continue;
                for ( int j = i+1 ; j <= n ; j++ ) {
                    if ( a[j] == c[i] && b[j] == d[i] ) {
                        swap(a[i], a[j]);
                        swap(b[i], b[j]);
                        ans.push_back({i,j});
                        break;
                    }
                }
            }
            cout << ans.size() << endl;
            for ( auto x : ans ) {
                cout << x.first << " " << x.second << endl;
            }
        }



    }
}