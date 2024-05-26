#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    string compressedString(string word) {
        string ans;
        int n = word.length();
        for (int i = 0 ;i < n ; i++) {
            char ch = word[i];
            int cnt = 0;
            while(i < n && ch == word[i]) {
                cnt++;
                i++;
            }
            i--;
            while(cnt > 9) {
                ans += '9';
                cnt -= 9;
                ans += ch;
            }
            ans += '0' + cnt;
            ans += ch;
        }
        return ans;
    }
};