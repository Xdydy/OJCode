/**
 * @file 单调栈.cpp
 * @author DYkid (18029544890@feishu.uestc.cn)
 * @brief 
 * @version 0.1
 * @date 2022-04-05
 * 给出项数为 $n$ 的整数数列 a1…na_{1 \dots n}a1…n​。

    定义函数 f(i)f(i)f(i) 代表数列中第 iii 个元素之后第一个大于 aia_iai​ 的元素的下标，即 f(i)=min⁡i<j≤n,aj>ai{j}f(i)=\min_{i<j\leq n, a_j > a_i} \{j\}f(i)=mini<j≤n,aj​>ai​​{j}。若不存在，则 f(i)=0f(i)=0f(i)=0。

    试求出 f(1…n)f(1\dots n)f(1…n)。

 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define ll long long
#define maxn 3000005

int n ;
int a[maxn];
int ans[maxn];

int main ()
{
    IOS;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];

    stack<pair<int,int>> st;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( st.empty() ) {
            st.push({i,a[i]});
        }
        else 
        {
            while(st.size() && a[i] > st.top().second) 
            {
                ans[st.top().first] = i;
                st.pop();
            }
            st.push({i,a[i]});
        }
    }
    while(st.size()) 
    {
        ans[st.top().first] = 0 ;
        st.pop();
    }
    for ( int i = 1 ; i <= n ; i++ )
        cout << ans[i] << " ";
    cout << endl; 
}