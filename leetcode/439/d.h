#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);



class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string ans(n+m-1,'?');
        vector<bool> vis(n+m+1, 0);
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (vis[i+j] && ans[i+j] != str2[j]) {
                        return "";
                    }
                    vis[i+j] = 1;
                    ans[i+j] = str2[j];
                }
            }
        }

        for (int i = 0; i < n+m-1; i++) {
            if (ans[i] == '?') {
                ans[i] = 'a';
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') continue;
            bool crushed = true;
            for (int j = 0; j < m; j++) {
                if (ans[i+j] != str2[j]) {
                    crushed = false;
                    break;
                }
            }
            if (crushed) {
                bool flag = 1;
                for (int j = i+m-1; j >=i ; j--) {
                    if (!vis[j]) {
                        flag = 0;
                        ans[j] = 'b';
                        break;
                    }
                }
                if (flag) {
                    return "";
                }
            }
        }
        return ans;
    }
};