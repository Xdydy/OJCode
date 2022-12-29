#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
string s;
string ans[maxn];
int vis[maxn][30];

int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        cin >> s;
        n = s.length();
        s = ' ' + s;
        for ( int i = 1 ; i <= 26 ; i++ )
            vis[n+1][i] = 0;
        for ( int i = n ; i >= 1 ; i-- )
        {
            for ( int j = 1 ; j <= 26 ; j++ )
                vis[i][j] = vis[i+1][j];
            int x = s[i] - 'a' + 1;
            vis[i][x]++;
        }

        int pos = 1;
        for ( int i = 1 ; i <= n ; i++ )
        {
            int x = s[i] - 'a' + 1;
            if (vis[i][x] > 1) continue;
            else 
            {
                pos = i;
                break;
            }
        }
        string res;
        for ( int i = pos ; i <= n ; i++ )
            res.push_back(s[i]);
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}