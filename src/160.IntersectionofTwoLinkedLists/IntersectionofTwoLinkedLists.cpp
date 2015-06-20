// Source: https://leetcode.com/problems/intersection-of-two-linked-lists/
// 2015/6/20

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *p = headA, *q = headB;
        int len_A = 0, len_B = 0;
        while (p) {
            ++len_A;
            p = p->next;
        }
        while (q) {
            ++len_B;
            q = q->next;
        }
        if (len_A >= len_B) {
            p = headA; q = headB;
        } else {
            p = headB; q = headA;
        }
        for (int i = 0; i < abs(len_A - len_B); ++i)
            p = p->next;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return !p ? NULL : p;
    }
}; // 48ms