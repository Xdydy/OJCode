#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e6+10)

struct Point {
    double x , y;
};
int mul ( Point p1 , Point p2 , Point p3 ) {
    return ( p2.x - p1.x ) * ( p3.y - p1.y ) - ( p3.x - p1.x ) * ( p2.y - p1.y );
}
bool judge ( Point p1 , Point p2 , Point q1 , Point q2 )
{
    if ( max( p1.x , p2.x ) < min( q1.x , q2.x ) ||
         max( q1.x , q2.x ) < min( p1.x , p2.x ) || 
         max( p1.y , p2.y ) < min( q1.y , q2.y ) || 
         max( q1.y , q2.y ) < min( p1.y , p2.y ) )
    return false;
    if ( 1ll * mul(p1,p2,q1) * mul(p1,p2,q2) <= 0 
        && 1ll*mul(q1,q2,p1) * mul(q1,q2,p2) <= 0 )
        return 1;
    return 0;
}