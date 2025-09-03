#include <bits/stdc++.h>
using namespace std;
#define maxn (int)(1e5+10)

int n;
string s;

int main () {
    cin >> n ;
    cin >> s;
    s = ' ' + s;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        int ch = s[i];
        int cnt = 0;
        while(i <= n && ch == s[i]) {
            cnt++;
            i++;
        }
        i--;
        v.push_back(cnt);
    }

    int last = v.size();
    if (last % 2 == 0) {
        last = last - 2;
    } else {
        last = last - 1;
    }

    int rest = 0;
    for (int cur = last; cur > 0; cur -= 2) {
        rest = max(0, rest + v[cur]-v[cur-1]);
    }
    cout << n-v[0]-rest << endl;
}