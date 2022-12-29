#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n , q;
vector<bool> ans;

int c1[maxn], c2[maxn];
int vis1[maxn], vis2[maxn];
int lowbit(int x) {
    return x & -x;
}
void add1(int x, int v) {
    while(x <= n+5) {
        c1[x] += v;
        x += lowbit(x);
    }
}
void add2(int x,int v) {
    while(x <= n+5) {
        c2[x] += v;
        x += lowbit(x);
    }
}
int qry1(int x) {
    int ret = 0;
    while(x) {
        ret += c1[x];
        x -= lowbit(x);
    }
    return ret;
}
int qry2(int x) {
    int ret = 0 ;
    while(x) {
        ret += c2[x];
        x -= lowbit(x);
    }
    return ret;
}

int main () {
    IOS;
    cin >> n >> q;
    for ( int i = 1 ; i <= q ; i++ ) {
        int t ; cin >> t;
        if (t == 1) {
            int x , y;
            cin >> x >> y;
            if ( vis1[x] == 0 ) {
                add1(x,1);
            }
            if ( vis2[y] == 0 ) {
                add2(y,1);
            }
            vis1[x]++;
            vis2[y]++;
        }
        else if (t == 2) {
            int x , y;
            cin >> x >> y;
            vis1[x]--;
            vis2[y]--;
            if ( vis1[x] == 0 )
                add1(x,-1);
            if ( vis2[y] == 0 )
                add2(y,-1);
        }
        else if ( t == 3 ) {
            int x1 , x2 , y1 , y2 ;
            cin >> x1 >> y1 >> x2 >> y2;
            int ret1 = qry1(x2) - qry1(x1-1);
            int ret2 = qry2(y2) - qry2(y1-1);
            bool flag = 0;
            if ( ret1 >= x2-x1+1 || ret2 >= y2-y1+1 ) {
                flag = 1;
            }
            ans.push_back(flag);
        }
    }

    for ( auto x : ans ) {
        if ( x ) cout << "Yes" << endl;
        else cout << "No" << endl; 
    }
}