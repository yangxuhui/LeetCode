// Source: https://leetcode.com/problems/insertion-sort-list/
// 2015/7/18

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        ListNode *ptr = head->next;
        head->next = NULL;
        while (ptr) {
            ListNode *temp = ptr->next;
            head = rinsertion(head, ptr);
            ptr = temp;
        }
        return head;
    }
private:
    ListNode* rinsertion(ListNode* p, ListNode *t) {
        if (p->val < t->val) {
            if (p->next) p->next = rinsertion(p->next, t);
            else {
                p->next = t;
                t->next = NULL;
            }
        }
        else {
            t->next = p;
            p = t;
        }
        return p;
    }
}; // 156ms