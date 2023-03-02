#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

string s;
int main () {
    
    cin >> s;
    int n = s.size();
    int pos = 0 ;
    s = ' ' + s;
    for ( int i = 1 ; i <=n ; i++  ) {
        if ( s[i] >= 'A' && s[i] <= 'Z' ) {
            pos = i ;
            break;
        }
    }
    cout << pos << endl;

}