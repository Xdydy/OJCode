#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int cur = 0;
        for (auto command: commands) {
            if (command == "UP") {
                cur -= n;
            } else if (command == "DOWN") {
                cur += n;
            } else if (command == "LEFT") {
                cur--;
            } else if (command == "RIGHT") {
                cur++;
            }
        }
        return cur;
    }
};