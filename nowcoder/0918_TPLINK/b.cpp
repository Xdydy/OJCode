#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int a[maxn];
int n;
int main() {
    n = 0;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        int x = 0;
        while(i < s.length() && s[i] != ' ') {
            x = x * 10 + s[i] - '0';
            i++;
        }
        a[++n] = x;
    }
    map<int,int> mp;
    for (int i = 1; i <= n; i++) {
        mp[a[i]]++;
    }
    int flag = -1;
    for (auto s: mp) {
        auto v = s.second;
        auto k = s.first;
        if (v > n/2) {
            flag = k;
            break;
        }
    }
    cout << flag << endl;
    // cout << n << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << endl;
    // }
}