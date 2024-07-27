#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int h,w;
int x,y;
char mp[55][55];
string ops;

bool judge(int r, int c) {
    if (r <= 0 || r > h) return false;
    if (c <= 0 || c > w) return false;
    return mp[r][c] == '.';
}

void move() {
    for (auto op : ops) {
        if (op == 'L') {
            if (judge(x,y-1)) {
                y--;
            }
        } else if (op == 'R') {
            if (judge(x,y+1)) {
                y++;
            }
        } else if (op == 'U') {
            if (judge(x-1, y)) {
                x--;
            }
        } else if (op == 'D') {
            if (judge(x+1,y)) {
                x++;
            }
        }
    }
}


int main() {
    cin >> h >> w;
    cin >> x >> y;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> mp[i][j];
        }
    }
    cin >> ops;
    move();
    cout << x << " " << y << endl;
}