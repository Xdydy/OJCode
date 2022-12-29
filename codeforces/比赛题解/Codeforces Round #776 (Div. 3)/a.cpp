#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
bool ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        string s ;
        char c;
        cin >> s;
        cin >> c;
        n = s.length();
        s = ' ' + s;
        bool flag = 0 ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( s[i] == c )
            {
                if ( (i-1) % 2 == 0 )
                {
                    flag = 1;
                    break;
                }
            }
        }
        ans[cas] = flag;
    }

    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}