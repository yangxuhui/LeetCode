// Source: https://leetcode.com/problems/path-sum-ii/
// 2015/7/15

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if (!root) return ret;
        stack<TreeNode*> s;
        vector<int> vec;
        while (root || !s.empty()) {
            s.push(root); vec.push_back(root->val);
            if (root->left) root = root->left;
            else if (root->right) {
                TreeNode *temp = root->right;
                root->right = NULL;
                root = temp;
            } else {
                if (accumulate(vec.begin(), vec.end(), 0) == sum) ret.push_back(vec);
                while (!s.empty() && !s.top()->right) {s.pop(); vec.pop_back(); }
                if (s.empty()) break;
                root = s.top()->right; s.top()->right = NULL;
            }
        }
    }
}; // 16ms