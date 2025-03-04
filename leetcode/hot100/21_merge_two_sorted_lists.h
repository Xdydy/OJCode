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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode* head = new ListNode();
        ListNode* p = head;
        bool flag = false;
        while(list1 != nullptr || list2 != nullptr) {
            if (flag) {
                p->next = new ListNode();
                p = p->next;

            }
            flag = 1;
            if (list1 == nullptr) {
                p->val = list2->val;
                list2 = list2->next;
            } else if (list2 == nullptr) {
                p->val = list1->val;
                list1 = list1->next;
            } else {
                if (list1->val <= list2->val) {
                    p->val = list1->val;
                    list1 = list1->next;
                } else {
                    p->val = list2->val;
                    list2 = list2->next;
                }
            }
        }
        return head;
    }
};