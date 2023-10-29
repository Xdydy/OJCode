#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans;
        int n = s.length();
        int cnt1 = 0 ;
        for ( auto ch : s ) {
            if ( ch =='1' ) {
                cnt1++;
            }
        }
        int cnt0 = n-cnt1;
        ans += '1';
        cnt1--;
        while(cnt0) {
            ans += '0';
            cnt0--;
        }
        while(cnt1) {
            ans += '1';
            cnt1--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};