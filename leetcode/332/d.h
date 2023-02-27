#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    int dp[maxn],dp2[maxn];
public:
    int minimumScore(string s, string t) {
        int n = s.length();
        int m = t.length();
        s  =  ' ' + s;
        t = ' ' + t;
        for ( int i = 1; i <= m ; i++ ) {
            dp[i] = n+1;
            dp2[i] = 0;
        }
        dp2[m+1] = (1<<29);
        vector<int> v[30],v2[30];
        for ( int i = 1 ; i <= n ; i++ ) {
            int ch = s[i]-'a';
            v[ch].push_back(i);
            v2[ch].push_back(-i);
        }
        for ( int i = 0 ; i <= 26 ; i++ ) {
            reverse(v2[i].begin(),v2[i].end());
        }
        for ( int i = 1 ; i <= m ; i++ ) {
            int ch = t[i]-'a';
            int pos = upper_bound(v[ch].begin(), v[ch].end(), dp[i-1]) - v[ch].begin();
            if ( pos == v[ch].size() ) {
                break;
            } else{
                dp[i] = v[ch][pos];
            }
        }
        for ( int i = m ; i >= 1 ; i-- ) {
            int ch = t[i] - 'a';
            int pos = upper_bound(v2[ch].begin(),v2[ch].end(), -dp2[i+1]) -v2[ch].begin();
            if ( pos == v2[ch].size() )  {
                break;
            } else {
                dp2[i] = -v2[ch][pos];
            }
        }
        int ans = m;

        int ans1 = lower_bound(dp+1,dp+1+m,n+1)-dp-1;
        ans = min(ans, m-ans1);
        ans1 = upper_bound(dp2+1,dp2+1+m,0)-dp2;
        ans = min(ans, ans1-1);

        for (  int i = 1;  i <= m ; i++ ) {
            cout << dp[i] << "\t";
        }
        cout << endl;
        for ( int i = 1; i <=m ; i++ ) {
            cout << dp2[i]  << "\t";
        }
        cout << endl;

        for ( int i = 1 ; i <= m ; i++ ) {
            if ( dp[i] == n+1) {
                break;
            }
            int left = i+1;
            int right = m+1;
            while(left<right) {
                int mid = left + right >> 1;
                if (dp2[mid] > dp[i]) {
                    right = mid;
                } else {
                    left = mid+1;
                }
            }
            if ( left <= m ) {
                ans = min(ans, left-i-1);
            } 
        }
        cout << ans << endl;
        return ans;
    }

};