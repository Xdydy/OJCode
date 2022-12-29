#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int n;
int a[maxn], b[maxn];
int ans[maxn];

int func(int x) {
    int res = 0 ;
    while(x) {
        res++;
        x /= 10;
    }
    return res;
}

int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        for ( int i = 1 ; i <= n ; i++ ) cin >> b[i];

        int res  = 0 ;
        multiset<int> st1,st2;
        for ( int i  = 1 ; i <= n ; i++ ) {
            st1.insert(a[i]);
        }
        for ( int i = 1 ; i <= n ; i++ ) {
            auto it = st1.find(b[i]);
            if ( it != st1.end() ) {
                st1.erase(it);
            }
            else {
                st2.insert(b[i]);
            }
        }


        multiset<int> tmp;
        for ( auto x : st1 ) {
            if ( x >= 10 ) {
                res++;
                tmp.insert(func(x));
            }
            else {
                tmp.insert(x);
            }
        }
        st1.clear();
        for ( auto x : tmp ) {
            st1.insert(x);
        }

        tmp.clear();

        for ( auto x : st2 ) {
            if ( x >= 10 ) {
                res++;
                tmp.insert(func(x));
            }
            else {
                tmp.insert(x);
            }
        }
        st2.clear();
        for ( auto x : tmp ) {
            st2.insert(x);
        }

        tmp.clear();

        for ( auto x : st2 ) {
            auto it = st1.find(x);
            if ( it != st1.end() ) {
                st1.erase(it);
            }
            else {
                tmp.insert(x);
            }
        }

        st2.clear();
        for ( auto x : tmp ) {
            st2.insert(x);
        }

        while(st1.size() && *st1.begin() == 1) {
            res++;
            st2.erase(st2.begin());
            st1.erase(st1.begin());
        }

        while(st2.size() && *st2.begin() == 1) {
            res++;
            st2.erase(st2.begin());
            st1.erase(st1.begin());
        }

        res += st1.size()*2;

        ans[cas] = res;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}