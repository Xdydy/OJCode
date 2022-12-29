#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);


int n;
string s;

int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        cin >> s;
        s = ' ' +s ;
        vector<ll> ans;
        ll cur = 0;
        priority_queue<int> pq;
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( s[i] == 'L' ) {
                cur += i-1;
                pq.push(max(0,n-i-i+1));
            }
            else if ( s[i] == 'R' ) {
                cur += n-i;
                pq.push(max(0,i-1-n+i));
            }
        }
        for ( int i = 1 ; i <= n ; i++ ) {
            int top = pq.top();
            pq.pop();
            cur += top;
            ans.push_back(cur);
        }
        for ( auto x : ans ) {
            cout << x << " " ;
        }
        cout << "\n";
    }
}