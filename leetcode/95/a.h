#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool flag1 = 0 , flag2 = 0;
        if ( length >= 1e4 || width >= 1e4 || height >= 1e4 || mass >= 1e4 )
            flag1 = 1;
        ll v = 1ll*length*width*height;
        if ( v >= 1e9 ) flag1 = 1;
        if ( mass >= 100 ) flag2 = 1;

        if (!flag1 && !flag2) {
            return "Neither";
        } else if ( flag1 && !flag2 ) {
            return "Bulky";
        } else if ( !flag1 && flag2 ) {
            return "Heavy";
        } else {
            return "Both";
        }
    }
};