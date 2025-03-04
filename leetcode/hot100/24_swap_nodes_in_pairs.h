#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* top = new ListNode();
        top->next = head;
        ListNode* lst = top;
        ListNode* cur = head;
        ListNode* pre = head->next;
        while(pre != nullptr && cur != nullptr) {
            ListNode* nxt = pre->next;
            cur->next = nxt;
            pre->next = cur;
            lst->next = pre;
            lst = cur;
            cur = nxt;
            if (nxt != nullptr) {
                pre = nxt->next;
            }
        }
        return top->next;
    }
};