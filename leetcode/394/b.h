#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans =0 ;
        vector<char> v[30];

        for (auto ch:word) {
            if(ch >= 'a' && ch <= 'z') {
                v[ch-'a'].push_back(ch);
            } else {
                v[ch-'A'].push_back(ch);
            }
        }
        for (int i = 0; i < 26 ; i++) {
            vector<int> tmp;
            for (int j = 0; j < v[i].size(); j++) {
                char ch = v[i][j];
                while(j < v[i].size() && v[i][j] == ch) {
                    j++;
                }
                j--;
                if (ch >= 'a' && ch <= 'z') {
                    tmp.push_back(0);
                } else {
                    tmp.push_back(1);
                }
            }
            if (tmp.size() == 2 && tmp[0] == 0) {
                ans++;
            }
        }
        return ans;
    }
};