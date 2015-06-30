// Source: https://leetcode.com/problems/remove-linked-list-elements/
// 2015/6/30

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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) head = head->next;
        for (ListNode *temp = head; temp; temp = temp->next)
            while (temp->next && temp->next->val == val)
                temp->next = temp->next->next;
        return head;
    }
}; // 36ms