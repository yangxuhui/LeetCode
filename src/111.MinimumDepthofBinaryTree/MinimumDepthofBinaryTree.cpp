// Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// 2015/6/2

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        else if (!root->left && !root->right) return 1;
        else if (!root->left || !root->right)
            return !root->left ? 1 + minDepth(root->right) : 1 + minDepth(root->left);
        else return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
}; // 12ms