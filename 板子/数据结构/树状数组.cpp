#include<bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long 

int n;
int c[max_size];
int lowbit ( int x ) {
    return x & -x ;
}
int sum ( int x ){
    int ret = 0;
    while ( x > 0 ){
        ret += c[x] ; x -= lowbit(x) ;
    }
    return ret;
}
void add ( int x , int d ) {
    while ( x <= n ){
        c[x] += d ; x += lowbit(x);
    }
}