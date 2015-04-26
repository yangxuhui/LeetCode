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

// Reference pezy
// (https://github.com/pezy/LeetCode/tree/master/023.%20Swap%20Nodes%20in%20Pairs)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        for (ListNode *p = newHead, *q = head; q && q->next; p = q, q = q->next) {
            p->next = q->next;
            q->next = p->next->next;
            p->next->next = q;
        }
        return newHead->next;
    }
}; // 4ms