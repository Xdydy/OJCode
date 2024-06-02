#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int minimumChairs(string s) {
        int maxx = 0;
        int cnt = 0 ;
        for (auto ch: s){
            if (ch == 'E') {
                cnt++;
            }
            else if (ch == 'L') {
                cnt--;
            }
            maxx = max(maxx, cnt);
        }
        return maxx;
    }
};