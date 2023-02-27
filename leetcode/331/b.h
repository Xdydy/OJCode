#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        set<char> st = {'a','e','i','o','u'};
        for ( int i = 1 ; i <= n ; i++ ) {
            string s = words[i-1];
            if (st.find(s.front()) != st.end() && st.find(s.back()) != st.end()) {
                a[i] = 1;
            } else {
                a[i] = 0 ;
            }
        }
        for ( int i = 1 ; i <= n ; i++ ) {
            pre[i] = pre[i-1] + a[i];
        }
        vector<int> ans;
        for ( auto ss : queries ) {
            int l = ss[0] + 1;
            int r = ss[1] + 1;
            ans.push_back(pre[r]-pre[l-1]);
        }
        return ans;
    }
private:
    int a[maxn];
    int pre[maxn];
};