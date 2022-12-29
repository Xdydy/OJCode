#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
int ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        string s;
        cin >> s;
        vector<int> v;
        for ( int i = 0 ; i < n ; i++ ) {
            char ch = s[i];
            int cnt = 0 ;
            while(i < n && s[i] == ch) {
                i++;
                cnt++;
            }
            i--;
            v.push_back(cnt);
        }   
        int res = 0;

        for ( int i = 0 ; i+1 < v.size() ; i++ ) {
            if ( v[i] & 1 ) {
                res++;
                v[i+1]--;
            }
        }   
        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}