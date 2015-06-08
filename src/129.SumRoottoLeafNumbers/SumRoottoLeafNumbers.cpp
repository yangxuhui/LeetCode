// Source: https://leetcode.com/problems/sum-root-to-leaf-numbers/
// 2015/6/8

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
    int sumNumbers(TreeNode* root) {
        return sumNumbers2(root, 0);
    }
private:
    int sumNumbers2(TreeNode* root, int val) {
        if (!root) return 0;
        else if (!root->left && !root->right) return val * 10 + root->val;
        else return sumNumbers2(root->left, val * 10 + root->val) + sumNumbers2(root->right, val * 10 + root->val); 
    }
}; // 4ms