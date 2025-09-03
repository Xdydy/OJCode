#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


struct ListNode {
    int val;
    ListNode* nxt;
};

ListNode* merge(ListNode* head1, ListNode* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }
    ListNode* top = nullptr;
    ListNode* p = nullptr;
    ListNode* tmp1 = head1;
    ListNode* tmp2 = head2;
    if (tmp1->val <= tmp2->val) {
        top = tmp1;
        tmp1 = tmp1->nxt;
    } else {
        top = tmp2;
        tmp2 = tmp2->nxt;
    }
    p = top;
    while(tmp1 != nullptr && tmp2 != nullptr) {
        if (tmp1->val <= tmp2->val) {
            p->nxt = tmp1;
            tmp1 = tmp1->nxt;
        } else {
            p->nxt = tmp2;
            tmp2 = tmp2->nxt;
        }
        p = p->nxt;
    }
    if (tmp1 != nullptr) {
        p->nxt = tmp1;
    }
    if (tmp2 != nullptr) {
        p->nxt = tmp2;
    }
    return top;
}

ListNode* sortList(ListNode* head) {
    ListNode* p = head;
    int n = 0;
    while(p != nullptr) {
        n++;
        p = p->nxt;
    }
    if (n == 1) {
        return head;
    }
    ListNode* head2 = head;
    ListNode* cur = head2;
    for (int i = 1; i <= n/2; i++) {
        cur = head2;
        head2 = head2->nxt;
    }
    cur->nxt = nullptr;
    
    auto res1 = sortList(head);
    // p = res1;
    // while(p != nullptr) {
    //     cout << p->val << " " ;
    //     p = p->nxt; 
    // }
    // cout << endl;
    auto res2 = sortList(head2);
    // p = res2;
    // while(p != nullptr) {
    //     cout << p->val << " " ;
    //     p = p->nxt; 
    // }
    // cout << endl;
    return merge(res1, res2);
}

int main() {
    ListNode* head = new ListNode();
    ListNode* p = head;
    for (int i = 5; i >= 0; i--) {
        p->val = i;
        if (i > 0) {
            p->nxt = new ListNode();
            p = p->nxt;
        }
    }
    auto res = sortList(head);
    p = res;
    while(p != nullptr) {
        cout << p->val << endl;
        p = p->nxt;
    }
}