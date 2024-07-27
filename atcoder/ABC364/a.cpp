#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
string s[105];

int main () {
    cin >> n;
    for (int i = 1; i <= n ; i++)  {
        cin >> s[i];
    }
    int pos = n;
    for (int i = 2; i <= n; i++ ) {
        if (s[i] == "sweet" && s[i-1] == "sweet") {
            pos = i;
            break;
        }
    }
    if (pos >= n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" <<endl;
    }
}