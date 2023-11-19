#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int ans = 0 ;
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        int pos = -1;
        for ( int i = 0 ; i < min(len1,min(len2,len3)) ; i++ ) {
            char ch = s1[i];
            if (s2[i] == ch && s3[i] == ch) {
                pos = i;
                continue;
            } else {
                break;
            }
        }
        if (pos == -1) {
            return -1;
        } else {
            pos++;
            ans += len1 - pos;
            ans += len2 - pos;
            ans += len3 - pos;
            return ans;
        }
    }
};