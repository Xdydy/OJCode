#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ch[30];
        memset(ch,0,sizeof(ch));
        for (int i = 0; i < s.length(); i++) {
            ch[s[i]-'a'] = i;
        }
        int ans = 0 ;
        for (int i = 0; i < t.length(); i++) {
            ans += abs(ch[t[i]-'a']-i);
        }
        return ans;
    }
};