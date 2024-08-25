#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    bool judge(int x, int y) {
        vector<int> v1,v2;
        while(x) {
            v1.push_back(x%10);
            x /= 10;
        }
        while(y) {
            v2.push_back(y%10);
            y /= 10;
        }
        while(v1.size() < v2.size()) {
            v1.push_back(0);
        }
        while(v2.size() < v1.size()) {
            v2.push_back(0);
        }
        int val1 = -1;
        int val2 = -1;
        int cnt = 0;
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                if (!cnt) {
                    cnt++;
                    val1 = v1[i];
                    val2 = v2[i];
                } else if (cnt == 1) {
                    if (val1 != v2[i] || val2 != v1[i]) {
                        return false;
                    }
                    cnt++;
                } else {
                    return false;
                }
            }
        }
        if (!cnt) {
            return true;
        } else if (cnt == 2) {
            return true;
        } else {
            return false;
        }
    }
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int ans =0 ;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++){
                if (judge(nums[i], nums[j])) {
                    cout << nums[i] << " " << nums[j] << endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};