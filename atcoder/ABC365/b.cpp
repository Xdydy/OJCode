#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;

struct node {
    int a;
    int no;
    bool operator < (const node& o) {
        return a < o.a;
    }
}nodes[maxn];
int main () {
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ )  {
        cin >> nodes[i].a;
        nodes[i].no = i;
    }
    sort(nodes+1,nodes+1+n);
    cout << nodes[n-1].no << endl;
}