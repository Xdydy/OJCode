#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e6+10)

int len[max_size] , nex[max_size][26];
int fail[max_size] , s[max_size];
int n , totNode , last , cur;
long long ans , cnt[max_size];
int newnode ( int p ){
	for ( int i = 0 ; i < 26 ; i++ ) nex[totNode][i] = 0;
	cnt[totNode] = 0 ; len[totNode] = p;
	return totNode++;
}
void init(){
	totNode = last = n = 0;
	newnode(0) ; newnode(-1);
	s[0] = -1;
	fail[0] = 1;
}
int Fail(int x){
	while (s[n-len[x]-1] != s[n] ) x = fail[x];
	return x;
}
void insert( int ch , int i ){
	s[++n] = ch;
	cur = Fail(last);
	if (!nex[cur][ch]){
		int now = newnode(len[cur]+2);
		fail[now] = nex[Fail(fail[cur])][ch];
		nex[cur][ch] = now;
	}
	last = nex[cur][ch];
	cnt[last]++;
}