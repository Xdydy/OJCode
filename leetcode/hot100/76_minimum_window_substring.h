#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    int sch[55];
    int tch[55];
    bool judge() {
        for (int i = 0; i < 52; i++) {
            if (sch[i] < tch[i]) {
                return false;
            }
        }
        return true;
    }
    int getch(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return ch-'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            return ch-'A'+26;
        } else {
            return 0;
        }
    }
public:
    string minWindow(string s, string t) {
        memset(sch, 0, sizeof(sch));
        memset(tch, 0, sizeof(tch));
        int slen = s.length();
        int tlen = t.length();
        string ans;
        int minx = 1 << 29;
        int ansl, ansr;
        if (slen < tlen) {
            return ans;
        }
        for (int i =0 ; i < tlen; i++) {
            int ch = getch(t[i]);
            tch[ch]++;
        }
        for (int i = 0; i < tlen; i++) {
            int ch = getch(s[i]);
            sch[ch]++;
        }
        int left = 0, right = tlen-1;
        if (judge()) {
            minx = tlen;
            ansl = left;
            ansr = right;
            ans = s.substr(ansl, ansr-ansl+1);
            return ans;
        }
        while(right < slen) {
            while(right < slen && !judge()) {
                // cout << "not judge " << left << " " << right << "\n";
                right++;
                int ch = getch(s[right]);
                sch[ch]++;
            }
            if (right == slen) {
                break;
            }
            while(left <= right && judge()) {
                // cout << "judge " << left << " " << right << "\n";
                int len = right-left+1;
                if(len < minx) {
                    minx = len;
                    ansl = left, ansr = right;
                }
                int ch = getch(s[left]);
                left++;
                sch[ch]--;
            }
        }
        if (minx != 1 << 29) 
            ans = s.substr(ansl, ansr-ansl+1);
        return ans;
    }
};