#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full = numBottles;
        int em = 0;
        int res = 0;
        while(full) {
            em += full;
            res += full;
            full = 0;
            while(em >= numExchange) {
                em -= numExchange;
                full++;
                numExchange++;
            }
        }
        return res;
    }
};