#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
LL a[maxn];
bool ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        multiset<LL> st;
        LL sum = 0 ;
        for ( int i = 1;  i <= n ; i++ )
        {
            st.insert(a[i]);
            sum += a[i];
        }

        deque<LL> q;
        q.push_back(sum);
        while (q.size())
        {
            LL x = q.front() ; q.pop_front();
            auto it = st.find(x);
            if ( it == st.end() )
            {
                q.push_front((x+1)/2);
                q.push_front(x/2);
                if ( x == 1 ) break;
            }
            else 
            {
                st.erase(it);
            }
        }
        if ( q.empty() )
            ans[cas] = 1;
        else ans[cas] = 0;
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}