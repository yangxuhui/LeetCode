// Source: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// 2015/6/11

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        deque<TreeNode *> d;
        d.push_back(root);
        int indicator = 1;
        while (!d.empty()) {
            vector<int> tmp;
            if (indicator & 0x1)
                for (auto it = d.begin(); it != d.end(); ++it)
                    tmp.push_back((*it)->val);
            else 
                for (auto it = d.rbegin(); it != d.rend(); ++it)
                    tmp.push_back((*it)->val);
            ret.push_back(tmp);
            ++indicator;
            for (int i = d.size(); i > 0; --i) {
                TreeNode *p = d.front();
                d.pop_front();
                if (p->left) d.push_back(p->left);
                if (p->right) d.push_back(p->right);
            }
        }
        return ret;
    }
}; // 4ms