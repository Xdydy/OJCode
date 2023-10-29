#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        int n = nums.size();
        for ( int i = 0 ; i < n ; i++ ) {
            int val = nums[i];
            int cnt = 0;
            while(i < n && nums[i] == val ) {
                cnt++;
                i++;
            }
            i--;
            v.push_back(cnt);
        }

        sort(v.begin(),v.end());

        int minx = n;
        for ( int i = 2 ; i <= v.front()+1 ; i++ ) {
            int sum = 0 ;
            bool flag = true;
            for ( int j = 0 ; j < v.size() ; j++ ) {
                int k = v[j];
                int cnt = n;
                bool flag2 = false;
                for ( int y = 0 ; y*i <= k+y ; y++ ) {
                    if ((k+y) % i) continue;
                    flag2 = 1;
                    int x = (k+y) / i - y;
                    cnt = min(cnt,x+y);
                }
                if (!flag2) {
                    flag = false;
                    break;
                }

                sum += cnt;
            }
            if (flag) {
                minx = min(minx,sum);
            }
        }
        return minx;
    }
};