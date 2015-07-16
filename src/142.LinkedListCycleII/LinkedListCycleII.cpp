// Source: https://leetcode.com/problems/linked-list-cycle-ii/
// 2015/7/16

// Reference pezy
// https://github.com/pezy/LeetCode/tree/master/043.%20Linked%20List%20Cycle%20II
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next; fast = fast->next->next;
            if (slow == fast) {
                for (ListNode *entry = head; ; entry = entry->next, slow = slow->next)
                    if (entry == slow) return slow;
            }
        }
        return NULL;
    }
}; // 12ms