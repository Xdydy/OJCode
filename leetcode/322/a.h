#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    bool isCircularSentence(string s) {
        vector<string> words;
        for ( int i = 0 ; i < s.length() ; i++ ) {
            string tmp ;
            while(i < s.length() && s[i] != ' ' ) {
                tmp += s[i];
                i++;
            }
            words.push_back(tmp);
        }
        bool flag = true;
        for ( int i = 1 ; i < words.size() ; i++ ) {
            string cur = words[i];
            string pre = words[i-1];
            if ( cur.front() != pre.back() ) {
                flag = 0;
                break;
            }
        }
        string cur = words.back();
        string pre = words.front();
        if ( cur.back() != pre.front() ) {
            flag = 0;
        }
        return flag;
    }
};