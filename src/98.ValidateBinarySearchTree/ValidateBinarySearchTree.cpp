// Source: https://leetcode.com/problems/validate-binary-search-tree/
// 2015/7/19

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
    bool isValidBST(TreeNode* root) {
        vector<int> ivec;
        inorderTraverse(root, ivec);
        return isBST(ivec);
    }
private:
    void inorderTraverse(TreeNode *root, vector<int> &vec) {
        if (!root) return;
        inorderTraverse(root->left, vec);
        vec.push_back(root->val);
        inorderTraverse(root->right, vec);
    }
    bool isBST(vector<int> &vec) {
        for (int i = 1; i < vec.size(); ++i) 
            if (vec[i] <= vec[i-1]) return false;
        return true;
    }
}; // 16ms