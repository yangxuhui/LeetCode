// Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// 2015/6/5

// My Solution
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p = root;
        while (p && p->left) {
            TreeLinkNode *q = p;
            while (q->next) {
                q->left->next = q->right;
                q->right->next = q->next->left;
                q = q->next;
            }
            q->left->next = q->right;
            q->right->next = NULL;
            p = p->left;
        }
    }
}; // 24ms

// recurusive
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left && root->right)
            root->left->next = root->right;
        if (root->next && root->right)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
}; // 26ms