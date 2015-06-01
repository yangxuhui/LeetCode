// Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// 2015/6/1

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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            for (int i = 0; i < cnt; ++i) {
                TreeNode *p = q.front();
                q.pop();
                if (p) {
                    q.push(p->left); q.push(p->right);
                }
            }
            if (!q.empty()) ++depth;
        }
        return depth;
    }
}; // 12ms