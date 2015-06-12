// Source: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// 2015/6/12

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
    void flatten(TreeNode* root) {
        vector<TreeNode *> pre_vec;
        preorder(root, pre_vec);
        for (int i = 0, sz = pre_vec.size() - 1; i < sz; ++i) {
            pre_vec[i]->left = NULL;
            pre_vec[i]->right = pre_vec[i+1];
        }
    }
private:
    void preorder(TreeNode *root, vector<TreeNode *> &vec) {
        if (!root) return;
        vec.push_back(root);
        preorder(root->left, vec);
        preorder(root->right, vec);
    }
}; // 12ms

// Reference pezy
// (https://github.com/pezy/LeetCode/blob/master/060.%20Flatten%20Binary%20Tree%20to%20Linked%20List/solution.h)
class Solution {
public:
    void flatten(TreeNode* root) {
        for (; root; root = root->right) {
            if (root->left) {
                TreeNode *p = root->left;
                while(p->right) p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
        }
    }
}; // 8ms