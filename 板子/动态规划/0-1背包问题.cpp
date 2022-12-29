#include <bits/stdc++.h>
using namespace std;
#define max_size 13010
int n , W , w[max_size] , v[max_size] , f[max_size];

int main ()
{
    ios::sync_with_stdio(0);
    cin >> n >> W;
    for ( int i = 1 ; i <= n ; i++ ) cin >> w[i] >> v[i];
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = W ; j >= w[i] ; j-- )
            if ( f[j-w[i]] + v[i] > f[j] ) f[j] = f[j-w[i]] + v[i];
    cout << f[W] << endl;
}