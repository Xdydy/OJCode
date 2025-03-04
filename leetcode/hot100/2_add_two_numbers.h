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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *p1 = l1, *p2 = l2;
        int c = 0;
        int tmp = p1->val + p2->val;
        if (tmp >= 10)
            c = 1;
        ListNode *head = new ListNode(tmp % 10);
        ListNode *tail = head;
        p1 = p1->next, p2 = p2->next;
        while (p1 && p2) {
            tmp = p1->val + p2->val + c;
            if (tmp >= 10)
                c = 1;
            else
                c = 0;
            ListNode *p = new ListNode(tmp % 10);
            tail->next = p;
            tail = tail->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *p;
        if (p1)
            p = p1;
        else if (p2)
            p = p2;
        while (p) {
            tmp = p->val + c;
            if (tmp >= 10)
                c = 1;
            else
                c = 0;
            ListNode *temp = new ListNode(tmp % 10);
            tail->next = temp;
            tail = tail->next;
            p = p->next;
        }
        if (c)
            tail->next = new ListNode(1);
        return head;
    }
};