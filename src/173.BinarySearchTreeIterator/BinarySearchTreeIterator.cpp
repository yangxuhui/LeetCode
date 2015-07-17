// Source: https://leetcode.com/problems/binary-search-tree-iterator/
// 2015/7/17

// My Solution
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.empty() ? false : true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *temp = s.top();
        int ret = temp->val;
        s.pop();
        temp = temp->right;
        while (temp) {
            s.push(temp);
            temp = temp->left;
        }
        return ret;
    }
private:
    stack<TreeNode*> s;
}; // 28ms

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */