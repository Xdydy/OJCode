#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    vector<int> v[5005];
    bool judge(int i, int j) {
        vector<int> v1,v2;
        v1 = v[i];
        v2 = v[j];
        // while(x) {
        //     v1.push_back(x%10);
        //     x /= 10;
        // }
        // while(y) {
        //     v2.push_back(y%10);
        //     y /= 10;
        // }
        while(v1.size() < v2.size()) {
            v1.push_back(0);
        }
        while(v2.size() < v1.size()) {
            v2.push_back(0);
        }
        int cnt = 0;
        int cnt1[10];
        int cnt2[10];
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        // for (auto x : v1) {
        //     cnt1[x]++;
        // }
        // for (auto x : v2) {
        //     cnt2[x]++;
        // }

        vector<pair<int,int>> dis;
        for (int i = 0; i < v1.size(); i++) {
            cnt1[v1[i]]++;
            cnt2[v2[i]]++;
            if (v1[i] != v2[i]) {
                dis.push_back({v1[i], v2[i]});
                cnt++;
                if (cnt > 4) return false;
            }
        }
        if (cnt == 1) return false;
        if (cnt > 4) return false;
        bool flag = 1;
        for (int i = 0; i < 10; i++) {
            if(cnt1[i] != cnt2[i]) {
                flag = 0;
                break;
            }
        }
        if (!flag) return false;
        if (cnt == 0 || cnt == 2 || cnt == 3) {
            return true;
        } else if (cnt == 4) {
            for (int i = 0; i < cnt ; i++ ) {
                for (int j = i + 1; j < cnt; j++) {
                    if (dis[i].first == dis[j].second && dis[i].second == dis[j].first) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            return false;
        }
    }
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int ans =0 ;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            vector<int> tmp;
            while(x) {
                tmp.push_back(x % 10);
                x /= 10;
            }
            v[i] = tmp;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++){
                if (nums[i] == nums[j] || judge(i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};