// Source: https://leetcode.com/problems/binary-tree-inorder-traversal/
// 2015/5/30

// My Solution
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        std::stack<TreeNode *> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                ret.push_back(p->val);
                p = p->right;
            }
        }
        return ret;
    }
}; // 0ms