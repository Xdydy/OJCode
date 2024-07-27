#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int N;
ll X,Y;
ll a[maxn], b[maxn];

int main () {
    IOS;
    cin >> N;
    cin >> X >> Y;
    for (int i =  1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> b[i];
    }

    sort(a+1,a+1+N,greater<ll>());
    sort(b+1,b+1+N,greater<ll>());

    int mina = N;
    int minb = N;
    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += a[i];
        if (sum > X) {
            mina = i;
            break;
        }
    }
    sum = 0 ;
    for (int i = 1; i <= N; i++) {
        sum += b[i];
        if (sum > Y) {
            minb = i;
            break;
        }
    }
    cout << min(mina,minb) << endl;
}