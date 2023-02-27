#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
pair<int,int> ans[maxn];


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        if ( n % 2 == 0 ) {
            ans[cas] = {n/2,n/2};
        }
        else {
            int tmp = n/2;
            if ( tmp % 10 != 9 ) {
                ans[cas] = {n/2,n/2+1};
            } else {
                int sum = 0;
                int x  = n ;
                deque<int> v;
                while(x){
                    sum += x%10;
                    v.push_back(x%10);
                    x /= 10;
                } 
                reverse(v.begin(),v.end());
                int f = 0 ;
                sum /= 2;
                for ( auto& x : v ) {
                    int minx = min(sum,x);
                    f = f * 10 + minx;
                    x -= minx;
                    sum -= minx;
                }
                int s = 0  ;
                for ( auto x : v ) {
                    s = s * 10 + x;
                }
                ans[cas] = {f,s};
            }
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i].first << " " << ans[i].second << endl;
}