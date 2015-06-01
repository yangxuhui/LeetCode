// Source: https://leetcode.com/problems/symmetric-tree/
// 2015/6/1

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
    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        else if (!root->left || !root->right) return false;
        else return levelTraverse(root->left, root->right);
    }
private:
    bool levelTraverse(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode *> q1, q2;
        q1.push(root1); q2.push(root2);
        int cnt = 1;
        while (!q1.empty() && !q2.empty()) {
            for (int i = 1; i <= cnt; ++i) {
                TreeNode *p1 = q1.front(), *p2 = q2.front();
                q1.pop(); q2.pop();
                if (!p1 && !p2) continue;
                else if (!p1 || !p2) return false;
                else {
                    if (p1->val != p2->val) return false;
                    q1.push(p1->left); q1.push(p1->right);
                    q2.push(p2->right); q2.push(p2->left);
                }
            }
            cnt = q1.size();
        }
        if (q1.empty() && q2.empty()) return true;
        else return false;
    }
}; // 8ms