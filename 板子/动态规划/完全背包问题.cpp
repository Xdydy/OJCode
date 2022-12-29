#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, W, w[maxn], v[maxn], f[maxn];
int main() {
  cin >> W >> n;
  for (int i = 1; i <= n; i++) std::cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++)
    for (int l = w[i]; l <= W; l++)
      if ( f[l - w[i]] + v[i] > f[l] ) f[l] = f[l - w[i]] + v[i];
  cout << f[W];
  return 0;
}
