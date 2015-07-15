// Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return generateBST(nums, 0, nums.size());
    }
private:
    TreeNode* generateBST(vector<int>& nums, int begin, int end) {
        if (end - begin < 2) return (begin == end) ? NULL : new TreeNode(nums[begin]);
        int mid = (begin + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        TreeNode *l = generateBST(nums, begin, mid);
        TreeNode *r = generateBST(nums, mid + 1, end);
        root->left = l; root->right = r;
        return root;
    }
}; // 16ms