#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
class Solution {
private:
    struct Node {
        int left_val;
        int right_val;
        int val;
        int to_p;
        Node() {
            left_val = right_val = val = to_p = 0;
        }
    };
    map<TreeNode*, Node*> mp;
    void dfs(TreeNode* u) {
        if (u->left == nullptr && u->right == nullptr) {
            Node* node = new Node();
            node->left_val = node->right_val = 0;
            node->to_p = u->val;
            node->val = u->val;
            mp[u] = node;
            return;
        }
        Node* node = new Node();
        node->val = u->val;
        if (u->left) {
            dfs(u->left);
            Node* left = mp[u->left];
            node->left_val = max(0, left->to_p);
        }
        if (u->right) {
            dfs(u->right);
            Node* right = mp[u->right];
            node->right_val = max(0, right->to_p);
        }

        node->to_p = node->val + max(node->left_val, node->right_val);
        node->val += node->left_val + node->right_val;
        mp[u] = node;

    }
public:
    int maxPathSum(TreeNode *root) {
        dfs(root);
        int ans = -(1<<29);
        for (auto [k,v]: mp) {
            ans = max(ans, v->val);
        }
        return ans;
    }
};