#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int minOperations(int n) {
        vector<int> v;
        int cnt = 0 ;
        while((1<<cnt) <= n) {
            int val = (n>>cnt)&1;
            v.push_back(val);
            cnt++;
        }
        int ans = 0 ;
        v.push_back(0);
        for (int i = 0 ; i < v.size() ; i++ ){
            if ( v[i] == 0 ) continue;;
            int cnt = 0 ;
            while(i < v.size() && v[i] == 1 ) {
                cnt++;
                i++;
            }
            i--;
            ans++;
            if ( cnt > 1 ) {
                v[i+1] = 1;
            }
        }
        return ans;
    }   
};