#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    ll getNum(ll x1, ll x2){
        ll res = 0 ;
        vector<int> tmp;
        while(x2) {
            tmp.push_back(x2%10);
            x2 /= 10;
        }
        while(x1) {
            tmp.push_back(x1%10);
            x1 /= 10;
        }
        reverse(tmp.begin(),tmp.end());
        for ( auto x : tmp ) {
            res = res * 10 + x;
        }
        return res;
    }
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        ll res = 0 ;
        deque<int> q;
        for ( auto x : nums ) {
            q.push_back(x);
        }
        while(q.size()) {
            if (q.size()>=2) {
                ll top1 = q.front();
                ll top2 = q.back();
                q.pop_back();
                q.pop_front();
                res += getNum(top1,top2);
                cout << top1 << " " << top2 << endl;
                cout << getNum(top1,top2) << endl;;
            }
            else {
                ll top = q.front();
                q.pop_front();
                res += top;
            }
        }
        return res;
    }
};