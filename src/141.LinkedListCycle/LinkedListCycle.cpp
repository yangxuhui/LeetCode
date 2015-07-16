// Source: https://leetcode.com/problems/linked-list-cycle/
// 2015/7/16

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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *ptr = head;
        while (ptr->next && ptr->next != head) {
            ListNode *temp = ptr;
            ptr = ptr->next;
            temp->next = head;
        }
        return ptr->next == head ? true : false;
    }
}; // 12ms

// Reference pezy
// https://github.com/pezy/LeetCode/tree/master/007.%20Linked%20List%20Cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
}; // 12ms