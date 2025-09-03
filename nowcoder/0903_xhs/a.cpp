#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(2e5+10)

int n;
ll a[maxn];
ll fac[15];
int cnt[15];
int main () {
    cin >> n ;
    for (int i = 1 ;i <= n; i++) {
        cin >> a[i];
    }
    fac[0] = 1;
    for (int i = 1; i <= 10; i++) {
        fac[i] = fac[i-1] * 10;
    }
    deque<int> v;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        int c = 0 ;
        while(x) {
            v.push_back(x % 10);
            x /= 10;
            cnt[c]++;
            c++;
        } 
    }   
    ll sum = 0;
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 10; i >= 0; i--) {
        int x = cnt[i];
        // cout << i << " " << x << endl;
        while(x--) {
            sum += v.front() * fac[i];
            v.pop_front();
        }
    }
    cout << sum << endl;
    
}