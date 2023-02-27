#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int l=1,r=n;
        int minx=1,maxx=n;
        bool flag = 0 ;
        pair<int,int> res;
        while(l<r) {
            if ( a[l] == minx ) {
                l++;
                minx++;
            } else if ( a[l] == maxx ) {
                l++;
                maxx--;
            } else if ( a[r] == minx ) {
                r--;
                minx++;
            } else if ( a[r] == maxx ) {
                r--;
                maxx--;
            } else {
                flag = 1;
                res = {l,r};
                break;
            }
        }
        if (flag) {
            cout << res.first << " " << res.second << endl;
        } else {
            cout << -1 << endl;
        }
    }
}