#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
int b[maxn];

int main() {
    IOS;
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    for ( int i = 2 ; i <= n ; i++ ) {
        b[i] = a[i] - a[i-1];
    }
    int maxx = 1;
    for ( int i = 2 ; i <= n ; i++ ) {
        if ( b[i] == 1 ) {
            int cur = 1;
            int cnt = 0;
            while(i <= n && b[i] == cur) {
                i++;
                cnt++;
                cur = -cur;
                if ( cur < 0 ) cur--;
                else cur++;
            }
            i--;
            maxx = max(maxx,cnt+1);
        }
    }
    cout << maxx << endl;
}