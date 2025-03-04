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
    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        int n = 0;
        ListNode* p = head;
        while(p != NULL) {
            n++;
            p = p->next;
        }
        ListNode* tail = head;
        for (int i = 1; i <= n/2; i++) {
            tail = tail->next;
        }
        ListNode* pre = head->next;
        ListNode* cur = head;
        while(pre != tail) {
            ListNode* nxt = pre->next;
            pre->next = head;
            cur->next = nxt;
            head = pre;
            pre = nxt;
        }
        ListNode* t1 = head;
        ListNode* t2 = tail;
        if (n % 2) {
            t2 = t2->next;
        }
        while(t1 != tail) {
            if (t1->val != t2->val) {
                return false;
            }
            t1 = t1->next;
            t2 = t2->next;

        }
        return true;
    }
};