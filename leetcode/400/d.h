#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
int pre[maxn][35];
class Solution {
private:
    int caculate(int l, int r) {
        int res = 0;
        int len = r - l + 1;
        for (int i = 0; i <= 30; i++) {
            if (pre[r][i] - pre[l-1][i] == len) {
                res |= (1<<i);
            } 
        }
        return res;
    }
public:
    int minimumDifference(vector<int>& nums, int k) {
        n = nums.size();
        for (int i = 1; i <= n; i++ ) {
            a[i] = nums[i-1];
        }
        for (int i = 1; i <= n; i++) {
            int x = a[i];
            for (int j = 0; j <= 30; j++) {
                pre[i][j] = pre[i-1][j];
            }
            for (int j = 0; j <= 30; j++) {
                if (a[i] & (1<<j)) {
                    pre[i][j]++;
                }
            }
        }
        int minx = 1 << 30;
        for (int i = 1; i <= n; i++) {
            int l = i;
            int r = n+1;
            while(l < r) {
                int mid = l + r >> 1;
                if (caculate(i,mid) < k) {
                    r = mid;
                } else {
                    l = mid+1;
                }
            }   
            if (l <= n) {
                int res = caculate(i,l);
                minx = min(minx, abs(k-res));
            } else {
                int res = caculate(i,i);
                minx = min(minx, abs(k-res));
            }
            if (l < n) {
                int res = caculate(i,l+1);
                minx = min(minx, abs(k-res));
            }
            if (l > i) {
                int res = caculate(i,l-1);
                minx = min(minx, abs(k-res));
            }
        }
        return minx;
    }
};