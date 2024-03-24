#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxx = 0;
        int n = s.length();
        s = ' ' + s ;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int chs[30];
                memset(chs, 0, sizeof(chs));
                string t ;
                for (int k = i; k <= j ; k++) {
                    t += s[k];
                }
                for (auto ch: t) {
                    chs[ch-'a']++;
                }
                bool flag = true;
                for (int k = 0; k < 26; k++) {
                    if (chs[k] > 2) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    maxx = max(maxx, j-i+1);
                }
            }
        }
        return maxx;
    }
};