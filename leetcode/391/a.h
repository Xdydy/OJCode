#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int s = x;
        while(x) {
            sum += x % 10;
            x /= 10;
        }
        if (s % sum == 0) {
            return sum;
        } else {
            return -1;
        }
    }
};