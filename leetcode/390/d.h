#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(5e5 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int nex[maxn][26];
int cnt;
struct Node {
    int idx ;
    int len ;
} nodes[maxn];
class Solution {
public:
    void insert(int idx, string s) {
        int p = 0;
        int len = s.length();
        if (nodes[0].idx == -1 || len < nodes[0].len) {
            nodes[0].len = len;
            nodes[0].idx = idx;
        }
        for (int i = len-1; i >= 0; i--) {
            int ch = s[i] - 'a';
            if (!nex[p][ch]) {
                nex[p][ch] = ++cnt;
                nodes[cnt].idx = -1;
            }
            p = nex[p][ch];
            if (nodes[p].idx == -1 || len < nodes[p].len) {
                nodes[p].len = len;
                nodes[p].idx = idx;
            }
        }
    }

    int qry(string s) {
        int p = 0;
        int len = s.length();
        for (int i = len-1; i >= 0; i-- ) {
            char c = s[i];
            int ch = c - 'a';
            if (!nex[p][ch]) {
                return nodes[p].idx;
            }
            p = nex[p][ch];
        }
        return nodes[p].idx;
    }
    vector<int> stringIndices(vector<string> &wordsContainer,
                              vector<string> &wordsQuery) {
        cnt = 0;
        memset(nex[0],0,sizeof(nex[0]));
        nodes[0].idx = -1;
        vector<int> ans;
        for (int i = 0; i < wordsContainer.size(); i++) {
            string s = wordsContainer[i];
            insert(i, s);
        }
        for (auto s : wordsQuery) {
            ans.push_back(qry(s));
        }

        return ans;
    }
};