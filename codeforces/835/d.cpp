#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        a[0] = a[n+1] = 1<<30;
        int cnt = 0;
        bool flag = 1;
        for ( int i = 1 ; i <= n ; i++ ) {
            int val = a[i];
            int l = i;
            while(i <= n && a[i] == val) {
                i++;
            }
            i--;
            int r = i;
            if ( a[l-1] > a[l] && a[r] < a[r+1] ) {
                cnt++;
            }
        }
        ans[cas] = (cnt==1);
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}   