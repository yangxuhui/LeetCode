// Source: https://leetcode.com/problems/path-sum/
// 2015/6/3

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        else if (!root->left && !root->right) return root->val == sum ? true : false;
        else return hasPathSum(root->right, sum - root->val) || hasPathSum(root->left, sum - root->val);
    }
}; // 12ms