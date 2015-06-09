// Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 2015/6/9

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        return buildTree2(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
private:
    TreeNode* buildTree2(vector<int>& preorder, int b1, int e1, vector<int>& inorder, int b2, int e2) {
        if (b1 >= e1) return NULL;
        TreeNode *root = new TreeNode(preorder[b1]);
        int pos = 0;
        for (int i = b2; i < e2; ++i) 
            if (inorder[i] == preorder[b1]) {
                pos = i;
                break;
            }
        root->left = buildTree2(preorder, b1+1, b1+1+pos-b2, inorder, b2, pos);
        root->right = buildTree2(preorder, b1+1+pos-b2, e1, inorder, pos+1, e2);
        return root;
    }
}; // 60ms