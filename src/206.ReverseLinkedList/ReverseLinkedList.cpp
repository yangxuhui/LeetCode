// Source: https://leetcode.com/problems/reverse-linked-list/
// 2015/6/16

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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = head->next, *q = p->next;
        p->next = head; head->next = NULL;
        while (q) {
            ListNode *temp = q->next;
            q->next = p; p = q; q = temp;
        }
        return p;
    }
}; // 8ms