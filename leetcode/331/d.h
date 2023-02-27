#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    long long minCost(vector<int> &b1, vector<int> &b2) {
        map<int, int> mp;
        map<int, int> mp1, mp2;
        ll minx = 1 << 30;
        for (auto x : b1) {
            mp[x]++;
            mp1[x]++;
            minx = min(minx, 1ll*x);
        }
        for (auto x : b2) {
            mp[x]++;
            mp2[x]++;
            minx = min(minx ,1ll*x);
        }
        bool flag = 1;
        for (auto x : mp) {
            if (x.second & 1) {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            return -1;
        } else {
            ll res = 0;
            priority_queue<ll,vector<ll>,greater<ll>> pq1;
            priority_queue<ll> pq2;
            for (auto x : mp1) {
                if (mp1[x.first] > mp[x.first] / 2) {
                    int cnt = mp1[x.first] - mp[x.first] / 2;
                    while (cnt--) {
                        pq1.push(x.first);
                    }

                }
            }
            for (auto x : mp2) {
                if (mp2[x.first] > mp[x.first] / 2) {
                    int cnt = mp2[x.first] - mp[x.first] / 2;
                    while (cnt--) {
                        pq2.push(x.first);
                    }
                }
            }
            while (pq1.size()) {
                auto top1 = pq1.top();
                auto top2 = pq2.top();
                cout << top1 << " " << top2 << endl;
                pq1.pop();
                pq2.pop();
                res += min(2*minx,min(top1, top2));
            }
            return res;
        }
    }
};