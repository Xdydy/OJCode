#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n ;
string s[maxn];

int main() {
    set<string> st;
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ ) {
        st.insert(s[i]);
        cin >> s[i];
    }

    vector<char> v = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    bool flag3 = 1;
    bool flag1 = 1 , flag2 = 1;
    for ( int i = 1 ; i <= n ; i++ ) {
        char ch1 = s[i][0];
        if ( ch1 == 'H' || ch1 == 'D'|| ch1 == 'C' || ch1 == 'S' ) {

        }
        else {
            flag1 = 0 ;
            break;
        }
        char ch2 = s[i][1];
        bool tmp = 0;
        for ( auto x : v ) {
            if ( ch2 == x) {
                tmp = 1;
                break;
            }
        }
        if (!tmp) {
            flag2 = 0 ;
            break;
        }
        if (st.find(s[i]) != st.end() ) {
            flag3 = 0 ;
            break;
        }
        st.insert(s[i]);
    }
    if(flag1 && flag2 && flag3 ) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}