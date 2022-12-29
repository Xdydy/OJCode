#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e5 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m;
int a[maxn];
struct node 
{
    LL t;
    int p ;
    int no;
};
vector<node> op[maxn];
LL dp[maxn][115];

int main()
{
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for ( int i = 1 ; i <= n ; i++ )
            op[i].clear();
        for (int i = 1; i <= m; i++)
        {
            int e, t, p;
            cin >> e >> t >> p;
            if (op[e].empty())
                op[e].push_back({0, 0});
            op[e].push_back({t, p, i});
        }
        LL last = a[1];
        bool flag = 1;
        vector<int> ans;
        for (int task = 1; task <= n; task++)
        {
            int len = op[task].size() - 1;
            if ( len <= 0 )
            {
                flag = 0 ;
                break;
            }
            for (int i = 0; i <= len; i++)
                for (int j = 1; j <= 105; j++)
                    dp[i][j] = 1ll << 40;
            for ( int i = 0 ; i <= len ; i++ )
                dp[i][0] = 0;
            for (int i = 1; i <= len; i++)
            {
                auto ss = op[task][i];
                LL t = ss.t;
                int p = ss.p;
                for (int j = 100 ; j >= 1 ; j-- )
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j+1]);
                    if (j >= p)
                    {   
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - p] + t);
                    }
                }
            }
            if (dp[len][100] > last)
            {
                flag = 0;
                break;
            }
            else
            {
                last = last - dp[len][100] + a[task + 1] - a[task];
                int x = 100;
                for (int i = len; i >= 1; i--)
                {
                    if ( x <= 0 ) break;
                    auto ss = op[task][i];
                    LL t = ss.t;
                    int p = ss.p;
                    if (dp[i][x] == dp[i - 1][x])
                        continue;
                    ans.push_back(ss.no);
                    x -= p;
                }
            }
        }
        if (flag)
        {
            cout << ans.size() << endl;
            for ( auto x : ans )
                cout << x << " ";
            cout << endl;
        }
        else cout << -1 << endl;
    }
}