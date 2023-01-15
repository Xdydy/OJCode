#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class DataStream {
public:
    DataStream(int value, int k) {
        val=value;
        kk= k;
    }
    
    bool consec(int num) {
        q.push(num);
        if (num!=val) {
            cnt++;
        }
        if (q.size() > kk) {
            int top = q.front();
            if (top != val) cnt--;
            q.pop();
        }
        return q.size() == kk && cnt == 0 ;
    }
private:
    int val;
    int kk;
    int cnt = 0;
    queue<int> q;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */