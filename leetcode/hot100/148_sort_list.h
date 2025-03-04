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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        int n = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            n++;
            cur = cur->next;
        }
        ListNode* top = new ListNode(0, head);
        for (int len = 1; len < n; len <<= 1) {
            ListNode* pre = top;
            cur = top->next;
            while(cur != nullptr) {
                ListNode* head1 = cur;
                for (int i = 1; i < len && cur->next != nullptr; i++) {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for (int i = 1; i < len && cur != nullptr && cur->next != nullptr; i++) {
                    cur = cur->next;
                }
                ListNode* nxt = nullptr;
                if (cur != nullptr) {
                    nxt = cur->next;
                    cur->next = nullptr;
                }

                ListNode* merged = this->merge(head1, head2);
                pre->next = merged;
                while(pre->next != nullptr) {
                    pre = pre->next;
                }
                cur = nxt;
            }
        }   
        return top->next;
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* top = new ListNode(0);
        ListNode* p = top;
        ListNode* tmp1 = head1;
        ListNode* tmp2 = head2;
        while(tmp1 != nullptr && tmp2 != nullptr) {
            if (tmp1->val <= tmp2 -> val) {
                p->next = tmp1;
                tmp1 = tmp1->next;
            } else {
                p->next = tmp2;
                tmp2 = tmp2->next;
            }
            p = p->next;
        }
        if (tmp1 != nullptr) {
            p->next = tmp1;
        } else if (tmp2 != nullptr) {
            p->next = tmp2;
        }
        return top->next;
    }
};