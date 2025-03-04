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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode* top = new ListNode();
        top->next = head;
        ListNode* lst = top;
        ListNode* first = head;
        ListNode* last = head;
        while(last != nullptr) {
            bool flag = true;
            for (int i = 0; i < k; i++) {
                if (last != nullptr) {
                    last = last->next;
                } else {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                return top->next;
            }

            ListNode* pre = first->next;
            ListNode* cur = first;
            while(pre != last) {
                ListNode* nxt = pre->next;
                cur->next = nxt;
                pre->next = lst->next;
                lst->next = pre;
                
                pre = nxt;

            }
            lst = cur;
            first = last;
        }
        return top->next;
    }
};