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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if (n == 0) {
            return nullptr;
        }
        for (int len = 1; len < n ; len <<=1 ){
            for (int i = 0; i < n; i+=2*len) {
                ListNode* head1 = lists[i];
                ListNode* head2 = nullptr;
                if (i + len < n) {
                    head2 = lists[i+len];
                }
                lists[i] = merge(head1, head2);
            }
        }
        return lists[0];
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* top = new ListNode(0);
        ListNode* p = top, *p1 = head1, *p2 = head2;
        while(p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                p -> next = p1;
                p1 = p1->next;
            } else {
                p -> next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1 != nullptr) {
            p -> next = p1; 
        } else if (p2 != nullptr) {
            p -> next = p2;
        }
        return top->next;
    }
};