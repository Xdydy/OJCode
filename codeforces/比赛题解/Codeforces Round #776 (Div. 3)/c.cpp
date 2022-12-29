#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

struct node 
{
    int x , w;
    int no;
    bool operator < ( const node& rhs ) const {
        return w < rhs.w;
    }
}Node[maxn];
int n , m ;

int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        cin >> n >> m ;
        for ( int i = 1 ; i <= m ; i++ )
        {
            int x ; cin >> x;
            int w ; cin >> w;
            Node[i] = {x,w,i};
        }
        sort(Node+1, Node+1+m);
        LL sum = 0;
        deque<pair<int,int>> v;
        for ( int i = 1 ; i <= 2*n ; i++ )
        {
            sum += Node[i].w;
            v.push_back({Node[i].x, Node[i].no});
        }
        sort(v.begin(), v.end());
        cout << sum << endl;
        while (v.size())
        {
            auto s1 = v.front();
            auto s2 = v.back();
            v.pop_back();
            v.pop_front();
            cout << s1.second << " " << s2.second << endl;
        }
        
        
    }

}
