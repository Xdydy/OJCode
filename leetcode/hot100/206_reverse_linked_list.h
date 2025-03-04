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
// 1 -> 2 -> 3 -> 4 -> 5
// 2 -> 1 -> 3 -> 4 -> 5
// 3 -> 2 -> 1 -> 4 -> 5
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode* pre = head->next;
        ListNode* cur = head;
        while(pre != NULL) {
            ListNode* nxt = pre->next;
            pre->next = head;
            cur->next = nxt;
            head = pre;
            pre = nxt;
        }
        return head;
    }
};