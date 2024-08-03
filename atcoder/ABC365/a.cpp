#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int main() {
    int y;
    cin >> y;
    if (y % 4) {
        cout << "365" << endl;
    } else {
        if (y % 100) {
            cout << "366" << endl;
        } else {
            if (y % 400) {
                cout << "365" << endl;
            } else {
                cout << "366" << endl;
            }
        }
    }
}