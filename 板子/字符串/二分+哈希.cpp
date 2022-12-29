#include<bits/stdc++.h>
using namespace std;
#define maxn (int)(1e5+10)
#define LL long long 

int n;
LL hash1[maxn] , hash2[maxn];
LL f[maxn];
string s;
void Hash() {
    hash1[0] = hash2[n+1] = 0;
    f[0] = 1;
    for ( int i = 1 ; i <= n ; i++ ) {
        hash1[i] = hash1[i-1] * 131 + s[i] - 'a' + 1;
        f[i] = f[i-1] * 131;
    }
    for ( int i = n ; i >= 1 ; i-- )
        hash2[i] = hash2[i+1]*131+s[i]-'a'+1;
}
LL gethash1 ( int l , int r ) {
    return hash1[r] - hash1[l-1] * f[r-l+1];
}
LL gethash2 ( int l , int r ) {
    return hash2[l] - hash2[r+1]*f[r-l+1];
}