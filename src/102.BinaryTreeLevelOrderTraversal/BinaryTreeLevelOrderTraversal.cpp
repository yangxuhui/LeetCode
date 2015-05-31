// Source: https://leetcode.com/problems/binary-tree-level-order-traversal/
// 2015/5/31

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        while (!q.empty()) {
            vector<int> tmp;
            for (int i = 1; i <= cnt; ++i) {
                TreeNode *p = q.front();
                q.pop();
                if (p) {
                    tmp.push_back(p->val);
                    q.push(p->left);
                    q.push(p->right);
                }
            }
            if (tmp.size()) ret.push_back(tmp);
            cnt = q.size();
        }
        return ret;
    }
}; // 8ms