#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int a[maxn];
int pre[maxn];
class Solution {
public:
    int minimumDeletions(string word, int k) {
        sort(word.begin(), word.end());
        deque<int> v;
        int n = word.length();
        for (int i =0 ; i < n ; i++ ) {
            char ch = word[i];
            int cnt = 0 ;
            while(i < n && word[i] == ch) {
                cnt++;
                i++;
            }
            i--;
            v.push_back(cnt);
        }
        sort(v.begin(), v.end());
        int minx = n ;
        int sz = v.size();
        for (int i = 0 ; i < sz ; i++) {
            a[i+1] = v[i];
        }
        pre[0] = 0;
        for (int i = 1; i <= sz ; i++) {
            pre[i] = pre[i-1] + a[i];
        }
        for (int i = 1; i <= sz ; i++ ) {
            int pos = upper_bound(a+1,a+1+sz,a[i]+k) - a;
            pos--;
            int res1 = pre[i-1];
            int res2 = pre[sz] - pre[pos] - (a[i]+k)*(sz-pos);
            minx = min(minx, res1+res2);
        }
        return minx;
    }
};