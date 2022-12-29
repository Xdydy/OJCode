#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
int b[maxn];
int c[maxn];
int ans[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            b[i] = c[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        sort(c + 1, c + 1 + n, greater<int>());
        int v1,v2,con;
        v1=v2=con=0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i] && a[i] != c[i]) {
                con++;
            } else if (a[i] != b[i]) {
                v1++;
            } else if (a[i] != c[i]) {
                v2++;
            }
        }

        int minx = min(v1,v2);
        v1 -= minx ;
        v2 -= minx ;
        if ( v1 == 0 ) {
            if ( v2 < con ) {
                ans[cas] = 0;
            } else {
                ans[cas] = 1;
            }
        } else if ( v2 ==0 ){
            if ( v1 <= con ) {
                ans[cas] =  0;
            }
            else {
                ans[cas] = -1;
            }
        }
    }
    for (int i = 1; i <= T; i++) {
        if ( ans[i] == 1 ) {
            cout << "First" << endl;
        } else if (ans[i] == -1) {
            cout << "Second" << endl;
        } else {
            cout << "Tie" << endl;
        }
    }
}