// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// 2015/5/25

// My Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ret = NULL;
        bool flag = true;
        for (ListNode *p = head, *pre = NULL; p != NULL; p = p->next) {
            int cnt = 1;
            while (p && p->next && p->val == p->next->val) {
                p = p->next;
                ++cnt;
            }
            if (!p->next) {
                if (flag) {
                    return cnt == 1 ? p : NULL;
                } else {
                    pre->next = (cnt == 1 ? p : NULL);
                }
            } else if (cnt == 1) {
                if (flag) {
                    ret = p;
                    pre = ret;
                    flag = false;
                } else {
                    pre->next = p;
                    pre = pre->next;
                }
            }
        }
        return ret;
    }
}; // 8ms