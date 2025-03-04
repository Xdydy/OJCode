#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        ListNode* suf = head;
        ListNode* pre = head->next;
        while(pre != NULL) {
            if (pre == suf) {
                return true;
            }
            pre = pre->next;
            if (pre == NULL) {
                return false;
            }
            pre = pre->next;
            suf = suf->next;
        }
        return false;
    }
};