#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int cnt1 = 0, cnt2 = 0 ;
        int red1 = red, blue1 = blue;
        while(red1 || blue1) {
            if (cnt1 % 2 == 0) {
                if (red1 - (cnt1+1) >= 0) {
                    red1 -= cnt1+1;
                    cnt1++;
                } else {
                    break;
                }
            } else {
                if (blue1 - (cnt1+1) >= 0) {
                    blue1 -= cnt1 + 1;
                    cnt1++;
                } else {
                    break;
                }
            }
        }
        red1 = red, blue1 = blue;
        while(red1 || blue1) {
            if (cnt2 % 2 ) {
                if (red1 - (cnt2+1) >= 0) {
                    red1 -= cnt2+1;
                    cnt2++;
                } else {
                    break;
                }
            } else {
                if (blue1 - (cnt2+1) >= 0) {
                    blue1 -= cnt2 + 1;
                    cnt2++;
                } else{
                    break;
                }
            }
        }
        return max(cnt1, cnt2);
    }
};