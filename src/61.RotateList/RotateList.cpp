// Source: https://leetcode.com/problems/rotate-list/
// 2015/6/29

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int sz = 0;
        for (ListNode *p = head; p != NULL; p = p->next)
            ++sz;
        k = k % sz;
        if (k == 0) return head;
        ListNode *indicator = head;
        for (int i = 0; i < k; ++i) indicator = indicator->next;
        ListNode *newHead = head;
        for (; indicator->next; indicator = indicator->next) newHead = newHead->next;
        indicator->next = head;
        ListNode *temp = newHead;newHead = newHead->next; 
        temp->next = NULL;
        return newHead;
    }
}; // 13ms