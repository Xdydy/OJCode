#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        string s;cin >> s;
        int maxx = 1;
        for ( auto x : s ) {
            int ch = x-'a'+1;
            maxx = max(maxx,ch);
        }
        ans[cas] = maxx;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}