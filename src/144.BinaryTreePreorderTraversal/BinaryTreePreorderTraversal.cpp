// Source: https://leetcode.com/problems/binary-tree-preorder-traversal/
// 2015/6/14

// My Solution
// Recursive
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorderTraversal2(root, ret);
        return ret;
    }
private:
    void preorderTraversal2(TreeNode* root, vector<int> &v) {
        if (!root) return;
        v.push_back(root->val);
        preorderTraversal2(root->left, v);
        preorderTraversal2(root->right, v);
    }
}; // 0ms

// Iteratively
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            if (root) {
                ret.push_back(root->val);
                if (root->right) s.push(root->right);
                root = root->left;
            } else {
                root = s.top(); s.pop();
            }
        }
        return ret;
    }
}; // 0ms
