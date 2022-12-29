#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        vector<int> pos;
        for ( int i = 0 ; i < words.size() ; i++ ) {
            string x = words[i];
            if ( x == target ) {
                pos.push_back(i);
            }
        }
        if ( pos.empty() ) return -1;
        int ans =1 << 29;
        for ( int x : pos ) {
            int d1 = abs(startIndex-x);
            int d2 = n - d1;
            ans = min(ans, min(d1,d2));
        }
        return ans;
    }   
};