#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
string s;
int ans[maxn];
int pre1[maxn], pre0[maxn];
int suf1[maxn], suf0[maxn];


bool check(int mid) {
    bool flag = 0;
    for ( int i = 0 ; i <= mid ; i++ ) {
        int pos1 = upper_bound(pre1+1, pre1+1+n, i) - pre1 - 1;
        int pos2 = upper_bound(suf1+1, suf1+1+n, mid-i) - suf1 - 1;
        if ( pos1 + pos2 > n ) continue;
        if ( pre0[n-pos2] - pre0[pos1] <= mid ) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> s;
        n = s.length();
        s = ' ' + s;
        int cnt = 0;
        for ( int i = 1 ; i <= n ; i++ ) {
            pre0[i] = pre0[i-1];
            pre1[i] = pre1[i-1];
            if ( s[i] == '0' ) {
                pre0[i]++;
            }
            if ( s[i] == '1' ) {
                pre1[i]++;
                cnt++;
            }
        }

        suf1[n+1] = suf0[n+1] = 0;
        for ( int i = n ; i >= 1 ; i-- ) {
            suf1[i] = suf1[i+1];
            suf0[i] = suf0[i+1];
            if ( s[i] == '0' ) {
                suf0[i]++;
            }
            if ( s[i] == '1' ) {
                suf1[i]++;
            }
        }

        reverse(suf0+1, suf0+1+n);
        reverse(suf1+1, suf1+1+n);

        int left = 0 , right = cnt;
        while(left < right) {
            int mid = left + right >> 1;
            if ( check(mid) ) {
                right = mid;
            }
            else left = mid+1;
        }
        ans[cas] = right;



    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}