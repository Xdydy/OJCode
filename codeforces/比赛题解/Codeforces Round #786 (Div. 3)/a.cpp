#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(3e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
pair<int,int> ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        int a , b;
        cin >> a >> b ;
        if ( b % a == 0 ) {
            ans[cas] = {1,b/a};
        }
        else {
            ans[cas] = {0,0};
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i].first << " " << ans[i].second << endl;
}