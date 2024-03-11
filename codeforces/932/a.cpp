#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
string s;
string ans[maxn];

string solvelq() {
    return s;
}
string solverq() {
    string t1 = s;
    string t2 = s;
    reverse(t1.begin(), t1.end());
    return t1 + t2;
}


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        cin >> s;
        int len = s.length();
        int l = 0, r = len-1;
        bool flag = false;
        while(l < r) {
            if (s[l] < s[r]) {
                flag = 1;
                ans[cas] = solvelq();
                break;
            } else if (s[l] > s[r]) {
                flag = 1;
                ans[cas] = solverq();
                break;
            } else {
                l++;
                r--;
            }
        }
        if (!flag) {
            ans[cas] = solvelq();
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}