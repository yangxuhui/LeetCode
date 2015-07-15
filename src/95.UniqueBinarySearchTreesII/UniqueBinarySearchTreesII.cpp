// Source: https://leetcode.com/problems/unique-binary-search-trees-ii/
// 2015/7/15

// Reference https://leetcode.com/discuss/10254/a-simple-recursive-solution
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
    vector<TreeNode*> generateTrees(int n) {
        return generateBST(1, n);
    }
private:
    vector<TreeNode*> generateBST(int start, int end) {
        if (end - start < 1) return vector<TreeNode*>{(end - start == 0) ? new TreeNode(start) : NULL};
        vector<TreeNode*> ret;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generateBST(start, i - 1);
            vector<TreeNode*> right = generateBST(i + 1, end);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
}; // 24ms