// Source: https://leetcode.com/problems/binary-tree-right-side-view/
// 2015/7/1

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            ret.push_back(q.back()->val);
            for (int i = 0, sz = q.size(); i < sz; ++i) {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return ret;
    }
}; // 8ms