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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        stack<ListNode*> st;
        ListNode* p = head;
        while(p != nullptr) {
            st.push(p);
            p = p->next;
        }
        ListNode* cur = nullptr;
        while(n--) {
            cur = st.top();
            st.pop();
        }
        if (st.size()) {
            ListNode* pre = st.top();
            pre->next = cur->next;
        } else {
            head = head->next;
        }
        return head;
    }
};