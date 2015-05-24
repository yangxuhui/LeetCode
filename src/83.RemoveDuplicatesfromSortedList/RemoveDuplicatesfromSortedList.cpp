// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// 2015/5/24

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
        if (head == NULL) return head;
        for (ListNode *p = head, *q = p->next; q != NULL; q = q->next) {
            while (q && q->val == p->val) q = q->next;
            if (!q) {
                p->next = NULL;
                break;
            } else {
                p ->next = q;
                p = q;
            }
        }
        return head;
    }
}; // 16ms