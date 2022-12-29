#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int n,m;
struct node {
    int q;
    int s;
    bool operator < (const node& ths) const {
        return q < ths.q;
    }
}Node[maxn];
int cur[maxn];
int a[maxn];

bool check(int mid) {
    for ( int i = 1 ; i <= n ; i++ ) {
        cur[i] = 0;
    }
    for ( int i = 1 ; i <= m ; i++ ) {
        bool flag = 0;
        for ( int j = 1 ; j <= n ; j++ ) {
            if ( Node[i].q > a[j] ) continue;
            if ( Node[i].s + cur[j] <= mid ) {
                cur[j] += Node[i].s;
                flag = 1;
                break;
            }
        }
        if (!flag) return 0;
    }
    return 1;
}

int main () {
    cin >> m >> n ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> a[i];
    }
    for ( int i = 1 ; i <= m ; i++ ) {
        cin >> Node[i].q;
    }
    for ( int i = 1 ; i <= m ; i++ ) {
        cin >> Node[i].s;
    }
    sort(a+1,a+1+n);
    sort(Node+1,Node+1+m);

    int left = 1, right = 1 << 29;
    while(left < right) {
        int mid = left + right >> 1;
        if ( check(mid) ) {
            right = mid;
        }
        else left = mid+1;
    }
    cout << left << endl;
}