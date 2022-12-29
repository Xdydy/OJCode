#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e6+10)

int q[max_size] , a[max_size];
int n , k;
void getmin()
{
    int head = 0 , tail = 0;
    for ( int i = 1 ; i < k ; i++ )
    {
        while ( head <= tail && a[q[tail]] >= a[i] ) tail--;
        q[++tail] = i;
    }
    for ( int i = k ; i <= n ; i++ ) 
    {
        while ( head <= tail && a[q[tail]] >= a[i] ) tail--;
        q[++tail] = i;
        while ( q[head] <= i - k ) head++;
        cout << a[q[head]] << " ";
    }
    cout << endl;
}

void getmax ()
{
    int head = 0 , tail = 0;
    for ( int i = 1 ; i < k ; i++ )
    {
        while ( head <= tail && a[q[tail]] <= a[i] ) tail--;
        q[++tail] = i;
    }
    for ( int i = k ; i <= n ; i++ ) 
    {
        while ( head <= tail && a[q[tail]] <= a[i] ) tail--;
        q[++tail] = i;
        while ( q[head] <= i - k ) head++;
        cout << a[q[head]] << " ";
    }
    cout << endl;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    getmin();
    getmax();
    return 0;
}