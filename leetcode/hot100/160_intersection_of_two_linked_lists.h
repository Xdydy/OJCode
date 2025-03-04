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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        while(pA != NULL || pB != NULL) {
            if (pA == pB) {
                return pA;
            }
            if (pA == NULL) {
                pA = headB;
                pB = pB->next;
            } else if (pB == NULL) {
                pB = headA;
                pA = pA->next;
            } else {
                pA = pA->next;
                pB = pB->next;
            }
        }
        return nullptr;
    }
};