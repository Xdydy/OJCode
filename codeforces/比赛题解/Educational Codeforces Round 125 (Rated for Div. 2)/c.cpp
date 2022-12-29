#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
string s;
int a[maxn];
pair<int,int> ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        cin >> n;
        string s;
        cin >> s;
        s = ' ' + s;
        vector<char> v;
        int res1 = 0 ;
        int res2 = 0 ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( v.empty() )
            {
                v.push_back(s[i]);
            }
            else if ( v.back() == '(' )
            {
                if ( v.size() == 1 )
                {
                    v.clear();
                    res1++;
                }
                else if ( s[i] == '(' )
                {
                    v.push_back(s[i]);
                }
                else 
                {
                    v.clear();
                    res1++;
                }
            }
            else if ( v.back() == ')' )
            {
                if ( s[i] == ')' )
                {
                    v.clear();
                    res1++;
                }
                else if ( s[i] == '(' )
                {
                    v.push_back(s[i]);
                }
            }
        }
        res2 = v.size();
        ans[cas] = {res1, res2};
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i].first << " " << ans[i].second  << endl;
}