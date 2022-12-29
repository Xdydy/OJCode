#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define LL long long
#define maxn (int)(1e6 + 10)
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
bool ans[maxn];

bool check_one()
{
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( a[i] == 1 ) 
            cnt++;
    return cnt == 1 ;
}


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        if ( !check_one() )
            ans[cas] = 0 ;
        else 
        {
            deque<int> q;
            for ( int i = 1 ; i <= n ; i++ )
                q.push_back(a[i]);
            while(q.front() != 1)
            {
                int x = q.front();
                q.pop_front();
                q.push_back(x);
            }
            bool flag = 1;
            for ( int i = 1 ; i < q.size() ; i++ )
                if ( q[i] > q[i-1] && q[i] - q[i-1] > 1 )
                {
                    flag = false;
                    break;
                }
            ans[cas] = flag;
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}