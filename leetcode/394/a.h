#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans= 0 ;
        set<char> st;
        for (auto ch:word) {
            st.insert(ch);
        }
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            if (st.find(ch) != st.end() && st.find(ch-'a'+'A') != st.end()) {
                ans++;
            } 
        }
        return ans;
    }
};