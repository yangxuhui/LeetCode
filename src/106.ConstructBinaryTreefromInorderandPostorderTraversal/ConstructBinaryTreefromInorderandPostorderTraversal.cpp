// Source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// 2015/6/10

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree2(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
private:
    TreeNode* buildTree2(vector<int>& inorder, int b1, int e1, vector<int>& postorder, int b2, int e2) {
        if (b1 >= e1) return NULL;
        TreeNode *root = new TreeNode(postorder[e2-1]);
        int pos = 0;
        for (int i = b1; i < e1; ++i)
            if (inorder[i] == root->val) {
                pos = i;
                break;
            }
        root->left = buildTree2(inorder, b1, pos, postorder, b2, b2 + pos - b1);
        root->right = buildTree2(inorder, pos + 1, e1, postorder, b2 + pos - b1, e2 - 1);
        return root;
    }
}; // 39ms