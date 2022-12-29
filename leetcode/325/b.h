#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int takeCharacters(string s, int k) {
        int cnta = 0 , cntb = 0 , cntc = 0 ;
        for ( auto x : s ) {
            if ( x == 'a' ) cnta++;
            else if ( x == 'b' ) cntb++;
            else if ( x == 'c' ) cntc++;
        }
        if ( cnta < k || cntb < k || cntc < k ) return -1;
        int n = s.length();
        s = ' ' + s;
        for ( int i = 1 ; i <= n ; i++ ) {
            suma[i] = suma[i-1];
            sumb[i] = sumb[i-1];
            sumc[i] = sumc[i-1];
            char ch = s[i];
            if ( ch == 'a' ) suma[i]++;
            else if ( ch == 'b' ) sumb[i]++;
            else if ( ch == 'c' ) sumc[i]++;
        }

        int ans = 0;
        for ( int i = 1 ; i <= n ; i++ ) {
            int l = i-1 ; 
            int r = n;
            while(l < r) {
                int mid = l + r + 1 >> 1;
                int ca = suma[i-1] + suma[n] - suma[mid];
                int cb = sumb[i-1] + sumb[n] - sumb[mid];
                int cc = sumc[i-1] + sumc[n] - sumc[mid];
                if ( ca >= k && cb >= k && cc >= k ) {
                    l = mid;
                } 
                else {
                    r = mid-1;
                }
            }
            if ( l > i-1 ) {
                ans = max(ans, l-i+1);
            }
        }
        return n-ans;
    }
private:
    int suma[maxn] , sumb[maxn] , sumc[maxn];
};