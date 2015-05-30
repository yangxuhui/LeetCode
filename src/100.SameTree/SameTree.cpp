// Source: https://leetcode.com/problems/same-tree/
// 2015/5/27

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        queue<TreeNode*> p_que, q_que;
        p_que.push(p);
        q_que.push(q);
        while (!p_que.empty() && !q_que.empty()) {
            if (p_que.front() && q_que.front()) {
                if (p_que.front()->val != q_que.front()->val)
                    return false;
                p_que.push(p_que.front()->left);
                p_que.push(p_que.front()->right);
                q_que.push(q_que.front()->left);
                q_que.push(q_que.front()->right);
            } else if ((p_que.front() && !q_que.front()) || (!p_que.front() && q_que.front()))
                return false;
            p_que.pop();
            q_que.pop();
        }
        if (p_que.empty() && q_que.empty())
            return true;
        else
            return false;
    }
}; // 4ms

// Reference pezy
// (https://github.com/pezy/LeetCode/tree/master/003.%20Same%20Tree)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q) return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else if (!p && !q) return true;
        else return false;
    }
}; // 4ms