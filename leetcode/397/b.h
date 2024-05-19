#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxx = -(1<<29);
        for (int i = 0; i < k; i++) {
            vector<int> v;
            for (int j = i; j < energy.size(); j+=k) {
                v.push_back(energy[j]);
            }
            reverse(v.begin(), v.end());
            for (int j = 1; j < v.size(); j++) {
                v[j] += v[j-1];
            }
            int sum = -(1<<29);
            for (auto x : v) {
                sum = max(sum, x);
            }
            maxx = max(maxx, sum );
        }
        return maxx;
    }
};