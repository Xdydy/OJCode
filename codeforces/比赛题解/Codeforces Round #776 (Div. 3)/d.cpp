#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n ;
int a[maxn];
int ans[maxn];

void print() {
    for ( int i = 1 ; i <= n ; i++ )
        cout << ans[i] << " ";
    cout << endl;
}

int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        cin >> n ;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        deque<int>q;
        for ( int i = 1 ; i <= n ; i++ )
            q.push_back(a[i]);
        for ( int i = n ; i >= 1 ; i-- )
        {
            int cnt = 0;
            while(q.back() != i)
            {
                int x = q.front();
                q.pop_front();
                q.push_back(x);
                cnt++;
            }
            q.pop_back();
            ans[i] = cnt;
        }
        print();
    }
}