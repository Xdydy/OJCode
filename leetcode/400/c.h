#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    string clearStars(string s) {
        set<int> re;
        int n = s.length();
        set<pair<char,int>> chars;
        for (int i = 0; i < n ; i++) {
            if (s[i] == '*') {
                re.insert(i);
                re.insert(n-(*chars.begin()).second);
                chars.erase(chars.begin());
            } else {
                chars.insert({s[i],n-i});
            }
        }
        string ans ;
        for (int i = 0 ; i < n; i++) {
            if (re.find(i) == re.end()) {
                ans += s[i];
            }
        }
        return ans;
    }
};