// Source: https://leetcode.com/problems/binary-tree-postorder-traversal/
// 2015/6/15

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postorderTraversal2(root, ret);
        return ret;
    }
private:
    void postorderTraversal2(TreeNode *root, vector<int> &vec) {
        if (!root) return;
        postorderTraversal2(root->left, vec);
        postorderTraversal2(root->right, vec);
        vec.push_back(root->val);
    }
}; // 0ms