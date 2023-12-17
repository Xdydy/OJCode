#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int a[maxn];
int l[maxn],r[maxn];
vector<int> v;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        v.clear();
        stack<pair<int,int>> st;
        int n = nums.size();
        int maxx = 0;
        for ( int i = 1 ; i <= n; i++ ) {
            int x = nums[i-1];
            a[i] = x;
            maxx = max(maxx,x);
        }

        for (int i = 1; i <= n ; i++ ){
            if (a[i] == maxx) {
                v.push_back(i);
            }
        }

        for (int i = 1; i <= n ; i++) {
            while(st.size() && st.top().second < a[i]) {
                r[st.top().first] = i-1;
                st.pop();
            }
            st.push({i,a[i]});
        }
        while(st.size()) {
            r[st.top().first] = n;
            st.pop();
        }

        for ( int i = n; i >= 1; i--) {
            while(st.size() && st.top().second <= a[i]) {
                l[st.top().first] = i+1;
                st.pop();
            }
            st.push({i,a[i]});
        }
        while(st.size()) {
            l[st.top().first] = 1;
            st.pop();
        }

        ll ans = 0 ;
        for ( int i = 0 ; i < v.size() ; i++ ) {
            int index = v[i];
            int left = l[index];
            if (i + k - 1 >= v.size()) break;
            ans += 1ll*(index-left+1)*(n-v[i+k-1]+1);
        }
        return ans;
    }

};