#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    bool isNum(char op) {
        return op >= '0' && op <= '9';
    }
    bool isOp(char op) {
        return op == '+' || op == '-' || op == '*' || op == '/';
    }
    bool check(string s) {
        int len = s.length();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                sum++;
                if(i > 0 && !isOp(s[i-1]) && s[i-1] != '(') {
                    return false;
                }
            } else if (s[i] == ')') {
                sum--;
                if (sum < 0 || i == 0) {
                    return false;
                }
                if (!isNum(s[i-1]) && s[i-1] != ')') {
                    return false;
                }
                i++;
            } else if (isOp(s[i])) {
                return false;
            } else {
                while(i < len && isNum(s[i])) {
                    i++;
                }
                if (!isOp(s[i])) {
                    i--;
                }
            }
        }
        return sum == 0;
    }
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 根据输入的四则运算表达式输出计算结果，表达式非法，返回-1 ；计算过程异常，返回-2
     * @param express string字符串  表达式
     * @return int整型
     */
    int calculate(string express) {
        if (!check(express)) {
            return -1;
        }
        auto calc = [](ll a, ll b, char op){
            if (op == '+') {
                return a + b;
            }
            if (op == '-') {
                return a - b;
            }
            if ( op == '*') {
                return a * b;
            } 
            if (op == '/') {
                if (b == 0) {
                    return 1ll << 60;
                }
                return a / b;
            }
            return 1ll << 59;
        };
        int flag = 0;
        stack<ll> value;
        stack<char> ops;
        int len = express.length();
        for (int i = 0; i < len; i++) {
            char ch = express[i];
            if (ch >= '0' && ch <= '9') {
                ll x = 0;
                while(i < len && express[i] >= '0' && express[i] <= '9') {
                    x = x * 10 + express[i] - '0';
                    i++;
                }
                i--;
                value.push(x);
            } else if (ch == '(') {
                ops.push(ch);
            } else if (ch == '*' || ch == '/') {
                ops.push(ch);
            } else if (ch == '+' || ch == '-') {
                while(ops.size() && (ops.top() == '*' || ops.top() == '/')) {
                    auto op = ops.top();
                    ops.pop();
                    if (value.empty()) {
                        return -1;
                    }
                    auto b = value.top();
                    value.pop();
                    if (value.empty()) {
                        return -1;
                    }
                    auto a = value.top();
                    value.pop();
                    auto tmp = calc(a,b,op);
                    if (tmp == 1ll<<60) {
                        return -2;
                    }
                    value.push(tmp);
                }
                ops.push(ch);
            } else if (ch == ')') {
                if (ops.empty()) {
                    return -1;
                } 
                if (ops.top() == '(') {
                    return -1;
                }
                while(ops.size() && ops.top() != '(') {
                    auto op = ops.top();
                    ops.pop();
                    if (value.empty()) {
                        return -1;
                    } 
                    auto b = value.top();
                    value.pop();
                    if (value.empty()) {
                        return -1;
                    }
                    auto a = value.top();
                    value.pop();
                    auto tmp = calc(a,b,op);
                    if (tmp == 1ll << 60) {
                        return -2;
                    }
                    value.push(tmp);
                }
                if (ops.empty()) {
                    return -1;
                }
                ops.pop();
            }
            // cout << i << " " << value.size() << " " << ops.size() << endl;
        }
        while(ops.size()) {
            auto op = ops.top();
            ops.pop();
            if (value.empty()) {
                return -1;
            }
            auto b = value.top();
            value.pop();
            if (value.empty()) {
                return -1;
            }
            auto a = value.top();
            value.pop();
            auto tmp = calc(a,b,op);
            if (tmp == 1ll << 60) {
                return -2;
            }
            if (tmp == 1ll << 59) {
                return -1;
            }
            value.push(tmp);
        }
        if (value.size() != 1) {
            return -1;
        }
        return value.top();
    }
};

int main () {
    Solution res;
    cout << res.calculate("10-2*3") << endl;
    cout << res.calculate("5++3") << endl;
    cout << res.calculate("1+5/0") << endl;
    cout << res.calculate("(1+2)*3") << endl;
    cout << res.calculate("3") << endl;
    cout << res.calculate("123(+1)") << endl;
    cout << res.calculate("()") << endl;
}
