#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

pair<int,int> a[maxn];

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n);

        for ( int i = 0 ; i < n ; i++ ) {
            a[i+1] = {nums[i],i};
        }

        sort(a+1,a+1+n); 
        // for (int i = 1; i <= n ; i++) {
        //     cout << a[i].first << " " << a[i].second << endl;
        // }
        for ( int i = 1 ; i <= n ; i++ ) {
            int start = i;
            deque<int> tmp;
            tmp.push_back(a[i].second);
            i++;
            while (i <= n && abs(a[i].first-a[i-1].first) <= limit) {
                tmp.push_back(a[i].second);
                i++;
            }
            i--;
            int ed = i;
            sort(tmp.begin(),tmp.end());
            for ( int i = start ; i <= ed ; i++ ) {
                a[i].second = tmp.front();
                tmp.pop_front();
            }

        }

        for (int i=1 ; i <= n ; i++ ) {
            int index = a[i].second;
            int val = a[i].first;
            ans[index] = val;
        }
        return ans;
    }
};