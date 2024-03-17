#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.length();
        s = ' ' + s;
        bool flag=false;
        for (int i = 1; i < n; i++) {
            for ( int j = 2; j <= n ; j++ ) {
                if (s[i] == s[j] && s[i+1] == s[j-1]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        return flag;
    }
};