// Source: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            vector<int> tmp;
            for (int i = 0; i < cnt; ++i) {
                TreeNode *p = q.front();
                q.pop();
                if (p) {
                    tmp.push_back(p->val);
                    q.push(p->left); q.push(p->right);
                }
            }
            if (!q.empty()) ret.push_back(tmp);
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
}; // 8ms