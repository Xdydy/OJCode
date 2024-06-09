#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int numberOfChild(int n, int k) {
        k %= 2*(n-1);
        if (k < n) {
            return k;
        } else {
            k -= (n-1);
            return n-k-1;
        }
    }
};