#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

const ll mod = 1e9 + 7;
class Solution {
private:
    struct Matrix {
        ll a[30][30] = {0};

        Matrix operator*(const Matrix &m) {
            Matrix res;
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    ll sum = 0;
                    for (int k = 0; k < 26; k++) {
                        sum += a[i][k] * m.a[k][j] % mod;
                        sum %= mod;
                    }
                    res.a[i][j] = sum;
                }
            }
            return res;
        }
        Matrix mul(int t) {
            Matrix res;
            for (int i = 0; i < 26; i++) {
                res.a[i][i] = 1;
            }
            Matrix x;
            memcpy(x.a, a, sizeof(a));
            while (t) {
                if (t & 1) {
                    res = res * x;
                }
                x = x * x;
                t >>= 1;
            }
            return res;
        }
    };
    Matrix mul(Matrix &a, Matrix &b) {
        Matrix c;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ll sum = 0;
                for (int k = 0; k < 26; k++) {
                    sum += a.a[i][k] * b.a[k][j] % mod;
                    sum %= mod;
                }
                c.a[i][j] = sum;
            }
        }
        return c;
    }
    Matrix pow(Matrix a, int t) {
        Matrix res;
        for (int i = 0; i < 26; i++) {
            res.a[i][i] = 1;
        }
        while (t) {
            if (t & 1) {
                res = mul(res, a);
            }
            a = mul(a,a);
            t >>= 1;
        }
        return res;
    }

public:
    int lengthAfterTransformations(string s, int t, vector<int> &nums) {
        Matrix r;
        memset(r.a, 0, sizeof(r.a));
        for (int i = 0; i < 26; i++) {
            int x = nums[i];
            for (int j = i+1; j <= i+nums[i]; j++) {
                r.a[i][j%26] = 1;
            }
        }
        Matrix r2 = pow(r, t);
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (auto ch : s) {
            cnt[ch - 'a']++;
        }
        ll mul[26];
        ll ans = 0;
        for (int i = 0; i < 26; i++) {
            mul[i] = 0;
            for (int j = 0; j < 26; j++) {
                mul[i] += r2.a[i][j];
                mul[i] %= mod;
            }
            ans += mul[i] * cnt[i] % mod;
            ans %= mod;
        }
        return ans;
    }
};