#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* ans = new Node(head->val);
        Node* ph = head;
        Node* th = ans;
        map<Node*,Node*> mp;
        mp[ph] = th;
        while(ph->next != nullptr) {
            ph = ph->next;
            th->next = new Node(ph->val);
            th = th->next;
            mp[ph] = th;
        }
        ph = head;
        th = ans;
        while(ph != nullptr) {
            if (ph->random != nullptr) {
                th->random = mp[ph->random];
            }
            ph = ph->next;
            th = th->next;
        }
        return ans;
    }
};