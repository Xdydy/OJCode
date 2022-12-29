#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);



int n , C ;
int m ;
LL bst[maxn];

LL ans[maxn];




int main ()
{
    IOS;
    cin >> n >> C ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        LL c , d , h;
        cin >> c >> d >> h;
        bst[c] = max(bst[c], d*h);
    }

    for ( int c = 1 ; c <= C ; c++ )
        for ( int xc = c ; xc <= C ; xc += c )
            bst[xc] = max(bst[xc], bst[c] * (xc/c));
    for ( int i = 1 ; i <= C ; i++ )
        bst[i] = max(bst[i], bst[i-1]);

    cin >> m ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        LL D , H;
        cin >> D >> H;
        int pos = upper_bound(bst+1, bst+1+C, D*H) - bst;
        if ( pos == C+1 )
            ans[i] = -1;
        else ans[i] = pos;
    }
    for ( int i = 1 ; i <= m ; i++ )
        cout << ans[i] << " ";
    cout << endl;
}