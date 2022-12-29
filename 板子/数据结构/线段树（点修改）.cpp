#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e5+10)
#define LL long long 

LL a[max_size];
struct node {
    int left , right;
    LL sum , maxx , minx ;
}Node[max_size];

void pushup ( int x ) {
    Node[x].sum = Node[x<<1].sum + Node[x<<1|1].sum;
    Node[x].maxx = max ( Node[x<<1].maxx , Node[x<<1|1].maxx );
    Node[x].minx = min ( Node[x<<1].minx , Node[x<<1|1].minx );
    return ;
}
void Build ( int x , int l , int r ) {
    Node[x].left = l , Node[x].right = r;
    if ( l == r ) {
        Node[x].sum = Node[x].maxx = Node[x].minx = a[x];
        return ;
    }
    int mid = l + r >> 1;
    Build ( x<<1 , l , mid ) , Build ( x<<1|1 , mid+1 , r );
    pushup(x);
}
void update ( int x , int pos , int d ) {
    if ( Node[x].left == Node[x].right ) {
        Node[x].sum += d;
        Node[x].maxx += d;
        Node[x].minx += d;
        return ;
    }
    int mid = Node[x].left + Node[x].right >> 1;
    if ( pos >= mid ) update ( x<<1|1 , pos , d );
    else if ( pos < mid ) update ( x<<1 , pos , d );
    pushup(x);
}
int query ( int x , int L , int R ) {
    if ( Node[x].left >= L && Node[x].right <= R ) {
        return Node[x].sum;
    }
    int mid = Node[x].left + Node[x].right >> 1;
    if ( L >= mid ) return query ( x<<1|1 , L , R );
    else if ( R < mid ) return query ( x<<1 , L , R );
    else return query ( x<<1 , L , mid ) + query ( x<<1|1 , mid+1 , R );
}