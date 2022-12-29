#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n ;
int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) {
        cin >> n ; 
        vector<pair<int,int>> ans;
        string s ;
        for ( int i = 1 ; i <= n ; i++ ) {
            s += "BAN";
        }
        s = ' ' + s;
        int left = 1 , right = 3*n;
        while(left < right) {
            ans.push_back({left,right});
            left += 3;
            right -= 3;
        }
        cout << ans.size() << endl;
        for ( auto x : ans ) {
            cout << x.first << " " << x.second << endl;
        }
    } 
}