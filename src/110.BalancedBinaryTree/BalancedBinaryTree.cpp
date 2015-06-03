// Source: https://leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        else if (abs(height(root->left) - height(root->right)) > 1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int height(TreeNode* root) {
        if (!root) return 0;
        else return std::max(height(root->left), height(root->right)) + 1;
    }
}; // 12ms