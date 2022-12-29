#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 105;
int n, m, ans;
struct Node {
  int a, b;  // a 代表时间，b 代表价值
  double f;
} node[N];

bool operator<(Node p, Node q) { return p.f > q.f; }

int f(int t, int v) {
  int tot = 0;
  for (int i = 1; t + i <= n; i++)
    if (v >= node[t + i].a) {
      v -= node[t + i].a;
      tot += node[t + i].b;
    } else
      return (int)(tot + v * node[t + i].f);
  return tot;
}

void work(int t, int p, int v) {
  ans = max(ans, v);
  if (t > n) return;
  if (f(t, p) + v > ans) work(t + 1, p, v);
  if (node[t].a <= p) work(t + 1, p - node[t].a, v + node[t].b);
}

int main() {
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &node[i].a, &node[i].b);
    node[i].f = 1.0 * node[i].b / node[i].a;
  }
  sort(node + 1, node + n + 1);
  work(1, m, 0);
  printf("%d\n", ans);
  return 0;
}
