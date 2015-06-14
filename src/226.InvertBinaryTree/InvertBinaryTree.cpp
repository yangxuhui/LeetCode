// Source: https://leetcode.com/problems/invert-binary-tree/
// 2015/6/13

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode *> q; q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front(); q.pop();
            swap(temp->left, temp->right);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        return root;
    }
}; 

// recurssive version
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode *temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;
        return root;
    }
};