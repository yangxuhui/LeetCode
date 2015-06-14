// Source: https://leetcode.com/problems/reverse-linked-list-ii/
// 2015/6/13

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *pre = fakeHead;
        for (int i = 1; i < m; ++i)
            pre = pre->next;
        ListNode *post = pre->next;
        for (int i = m; i <= n; ++i)
            post = post->next;
        pre->next = reverse(pre->next, n - m + 1);
        for (int i = 0; i < n - m + 1; ++i)
            pre = pre->next;
        pre->next = post;
        return fakeHead->next;
    }
private:
    ListNode* reverse(ListNode* head, int n) {
        if (n == 1) return head;
        ListNode *p = head, *q = p->next, *r = q->next;
        for (int i = 1; i < n; ++i) {
            q->next = p; p = q; 
            q = r;
            if (r) r = r->next;
        }
        return p;
    }
}; // 4ms