#include<bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long 

int Manacher ( string s ) {
    string temp = "$#";
    for ( int i = 0 ; i < s.length() ; i++ ) {
        temp += s[i];
        temp += '#';
    }
    vector <int> p(temp.length(),0);
    int mx = 0 , id = 0 , len = 0 , cter = 0;
    for ( int i = 1 ; i < temp.length() ; i++ )
    {
        p[i] = mx > i ? min ( p[id*2-i] , mx-i ) : 1;
        while ( temp[i+p[i]] == temp[i-p[i]] ) ++p[i];
        if ( mx < i + p[i] )
        {
            mx = i + p[i];
            id = i;
        } 
        if ( len < p[i] )
        {
            len = p[i];
            cter = i;
        }
    }
    return len-1;
}

int len[max_size] , nex[max_size][26];
int fail[max_size] , s[max_size];
int n , totNode , last , cur;
LL ans , cnt[max_size];
int newnode ( int p ){
    for ( int i = 0 ; i < 26 ; i++ ) nex[totNode][i] = 0;
    cnt[totNode] = 0 ; len[totNode] = p;
    return totNode++;
}
void init() {
    totNode = last = n = 0;
    newnode(0) ; newnode(-1);
    s[0] = -1;
    fail[0] = 1;
}
int Fail ( int x ) {
    while ( s[n-len[x]-1] != s[n] ) x = fail[x];
    return x;
}
void insert ( int ch ) {
    s[++n] = ch;
    cur = Fail ( last );
    if ( !nex[cur][ch] ) {
        int now = newnode(len[cur]+2) ;
        fail[now] = nex[Fail(fail[cur])][ch];
        nex[cur][ch] = now;
    }
    last = nex[cur][ch];
    cnt[last]++;
}
