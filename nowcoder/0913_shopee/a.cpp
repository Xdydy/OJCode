#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 
     * @param message string字符串  
     * @return string字符串
     */
    string reverseMessage(string message) {
        vector<string> ans;
        int len = message.length();
        for (int i = 0; i < len; i++) {
            string s;
            while(i < len && message[i] != ' ') {
                s += message[i];
                i++;
            }
            if (s.length() != 0) {
                ans.push_back(s);
            }
        }

        reverse(ans.begin(), ans.end());
        string res;
        for (int i = 0; i < ans.size(); i++) {
            res += ans[i];
            if (i < ans.size()-1) {
                res += ' ';
            }
        }
        return res;
    }
};

int main () {
    Solution res;
    cout << res.reverseMessage("a good   example") << endl;;
}