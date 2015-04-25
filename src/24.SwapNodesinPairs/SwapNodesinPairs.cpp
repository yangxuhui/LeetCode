// Source: https://leetcode.com/problems/swap-nodes-in-pairs/
// 2015/4/25

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // My Solution
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p = head, *q = p->next, *pre = NULL;
        ListNode *ret = q;
        while (p && q) {
            p->next = q->next;
            q->next = p;
            if (pre) pre->next = q;
            pre = p;
            p = pre->next;
            if (p) q = p->next;
        }
        return ret;
    }
}; // 6ms