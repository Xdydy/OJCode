#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
string s;
vector<string> v;
int ans;

bool checkString(string s) {
    if (s.length() == 1) {
        return true;
    }
    if (s[0] == '0') {
        return false;
    }
    int x = 0;
    for (int i = 0; i < s.length(); i++) {
        x = x * 10 + s[i] - '0';
        if (x > 255) {
            return false;
        }
    }
    return x <= 255;
}

bool check() {
    if (v.size() != 4) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        string si = v[i];
        if (!checkString(si)) {
            return false;
        }
    }
    return true;
}

void dfs(int pos, string curString) {
    if (pos == n+1) {
        v.push_back(curString);
        if (check()) {
            // for (auto x : v) {
            //     cout << x << " ";
            // }
            // cout << endl;
            ans++;
        }
        v.pop_back();
        return;
    }
    if (curString == "") {
        curString += s[pos];
        dfs(pos+1, curString);
    } else {
        v.push_back(curString);
        string tmp;
        tmp += s[pos];
        dfs(pos+1, tmp);
        v.pop_back();
        curString += s[pos];
        dfs(pos+1, curString);
    }
}

int main() {
    cin >> s;
    n = s.length();
    s = ' ' + s;
    ans = 0 ;
    dfs(1, "");
    cout << ans << endl;
}