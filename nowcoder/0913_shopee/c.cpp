#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


vector<int> solve(string s) {
    vector<int> res;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        int x = 0;
        while(i < len && s[i] >= '0' && s[i] <= '9') {
            x = x * 10 + s[i] - '0';
            i++;
        }
        res.push_back(x);
    }
    return res;
}

int main () {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> v1 = solve(s1);
    vector<int> v2 = solve(s2);
    int pos1 = 0, pos2 = 0;
    int flag = 0 ;
    while(pos1 < v1.size() && pos2 < v2.size()) {
        if (v1[pos1] < v2[pos2]) {
            flag = -1;
            break;
        } else if (v1[pos1] > v2[pos2]) {
            flag = 1;
            break;
        } else {
            pos1++;
            pos2++;
        }
    }
    if (flag == 1 || flag == -1) {
        cout << flag << endl;
    } else {
        while(pos1 < v1.size()) {
            if (v1[pos1] == 0) {
                pos1++;
            } else {
                flag = 1;
                break;
            }
        }
        while(pos2 < v2.size()) {
            if (v2[pos2] == 0) {
                pos2++;
            } else {
                flag = -1;
                break;
            }
        }
        cout << flag << endl;
    }
}