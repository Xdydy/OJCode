#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
int ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        string s;
        cin >> s;
        int ch1 = s[0] - 'a' ;
        int ch2 = s[1] - 'a' + 1;
        if ( ch2 > ch1 ) ch2--;
        ans[cas] = ch1 * 25 + ch2;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}