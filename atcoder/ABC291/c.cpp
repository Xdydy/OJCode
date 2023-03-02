#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
string s;

int main () {
    cin >> n;
    cin >> s;
    s = ' ' + s;
    set<pair<int,int>> st;
    int x = 0 , y = 0 ;
    st.insert({x,y});
    bool flag = 0;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( s[i] == 'L' ) {
            x--;
        } else if ( s[i] == 'R' ) {
            x++;
        } else if ( s[i] == 'U' ) {
            y++;
        } else if ( s[i] == 'D' ) {
            y--;
        }
        if (st.find({x,y}) != st.end() ) {
            flag =  1;
            break;
        } else {
            st.insert({x,y});
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}