#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Node {
public:
    int val;
    Node* next;
    Node* pre;
    Node(int x) {
        val = x;
        next = pre = nullptr;
    }
};

class LRUCache {
private:
    Node* top;
    Node* head;
    Node* tail;
    int len;
    int ca;
    map<int,Node*> mp;
    map<Node*,int> mp2;
public:
    LRUCache(int capacity) {
        this->ca = capacity;
        this->top = new Node(0);
        this->len = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* res = mp[key];
        if (res == head) {
            return res->val;
        } else {
            Node* pre = res->pre;
            Node* nxt = res->next;
            pre->next = nxt;
            if (nxt != nullptr) {
                nxt->pre = pre;
            }
            if (res == tail) {
                tail = pre;
            }
            res->pre = top;
            res->next = head;
            head->pre = res;
            top->next = res;
            head = res;
            return res->val;
        }
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            this->len++;
            if (this->len > this->ca) {
                this->len--;
                Node* cur = tail;
                if (head == tail) {
                    head = tail = nullptr;
                } else {
                    tail = tail->pre;
                    tail->next = nullptr;

                }
                int old_key = mp2[cur];
                mp.erase(old_key);
                mp2.erase(cur);
                delete cur;
            } 
            Node* node = new Node(value);
            mp[key] = node;
            mp2[node] = key;
            if (head != nullptr) {
                node->next = head;
                head->pre = node;
                head = node;
            } else {
                head = tail = node;
            }
            top->next = head;
            head->pre = top;
        } else {
            Node* res = mp[key];
            res->val = value;
            this->get(key);
        }
    }
};