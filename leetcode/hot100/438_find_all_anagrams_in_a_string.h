#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(3e4 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
private:
    int sch[30];
    int pch[30];
    bool judge() {
        for (int i = 0; i < 26; i++) {
            if (sch[i] != pch[i]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        memset(sch, 0, sizeof(sch));
        memset(pch, 0, sizeof(pch));
        for (auto x: p) {
            int ch = x-'a';
            pch[ch]++;
        }
        int plen = p.length();
        int slen = s.length();
        vector<int> ans;
        if (slen < plen) {
            return ans;
        }
        for (int i = 0; i < plen; i++) {
            int ch = s[i]-'a';
            sch[ch]++;
        }
        if (judge()) {
            ans.push_back(0);
        }
        for (int i = 1; i + plen - 1< slen; i++) {
            int ed = i + plen - 1;
            int lastch = s[i-1]-'a';
            sch[lastch]--;
            int newch = s[ed]-'a';
            sch[newch]++;
            if (judge()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};