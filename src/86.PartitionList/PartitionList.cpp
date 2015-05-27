// Source: https://leetcode.com/problems/partition-list/
// 2015/5/27

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
    ListNode* partition(ListNode* head, int x) {
        ListNode less_link = ListNode(0), great_link = ListNode(0);
        ListNode *p = &less_link, *q = &great_link;
        for (; head != NULL; head = head->next) {
            if (head->val < x) {
                p->next = head;
                p = p->next;
            } else {
                q->next = head;
                q = q->next;
            }
        }
        q->next = NULL;
        p->next = great_link.next;
        return less_link.next;
    }
}; // 8ms