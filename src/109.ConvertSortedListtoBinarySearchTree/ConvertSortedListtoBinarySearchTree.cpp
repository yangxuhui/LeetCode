// Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// 2015/7/15

// My Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        for (ListNode *ptr = head; ptr; ptr = ptr->next)
            nums.push_back(ptr->val);
        return generateBST(nums, 0, nums.size());
    }
private:
    TreeNode* generateBST(vector<int> &nums, int begin, int end) {
        if (end - begin < 2) return (begin == end) ? NULL : new TreeNode(nums[begin]);
        int mid = (begin + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = generateBST(nums, begin, mid);
        root->right = generateBST(nums, mid + 1, end);
        return root;
    }
}; // 28ms