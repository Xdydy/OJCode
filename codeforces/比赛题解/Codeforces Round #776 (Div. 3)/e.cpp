#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, d;
int a[maxn];
int ans[maxn];

bool move(int x, int mid)
{
    if ( x == 0 ) return false;
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;
        ;
        int len = 0;
        if (i - 1 == x)
            len = a[i] - a[i - 2] - 1;
        else
            len = a[i] - a[i - 1] - 1;
        if ( len == 0 ) continue;
        if ((len-1)/2 >= mid)
        {
            flag = 1;
            break;
        }
    }
    if ( flag ) return true;
    if ( x == n )
    {
        return d - a[n-1] - 1 >= mid ;
    }
    int len = d - a[n] - 1;
    if ( len >= mid)
        flag = 1;
    return flag;
}

bool check(int x)
{
    int cnt = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] - a[i - 1] - 1 < x)
        {
            cnt++;
            v.push_back(i);
        }
    }
    
    if (cnt >= 3)
        return false;
    else if (cnt == 2)
    {
        if (v[0] + 1 != v[1])
            return false;
        else if (a[v[1]] - a[v[0]-1] - 1 < x)
        {
            return false;
        }
        else
        {
            return move(v[0],x);
        }
    }
    else if (cnt == 1)
    {
        return move(v[0],x) || move(v[0]-1,x);
    }
    else
        return true;
}

int main()
{
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        LL left = -1, right = d;
        while (left < right)
        {
            LL mid = left + right + 1 >> 1;
            if (check(mid))
                left = mid;
            else
                right = mid - 1;
        }
        ans[cas] = left;
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i] << endl;
}