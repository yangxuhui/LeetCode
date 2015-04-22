// Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// 2015/4/21

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ret = head;
		/**
		 * pre is the previous node of the Nth Node,
		 * nex is the next node of the Nth Node,
		 * indicate is the node which use to indicate that nth is
		 * pointed to the Nth Node.
		 */
        ListNode *pre = NULL, *nth = head, *nex = nth->next, *indicate = nth;
		// indicate is the next Nth Node of nth,
		// so that when indicate is NULL, nth pointed to Nth Node From end of list 
        while (n != 0) {
            indicate = indicate->next;
            --n;
        }
		// move nth to pointed to Nth Node from end of list 
        while (indicate != NULL) {
            indicate = indicate->next;
            pre = nth;
            nth = nex;
            nex = nex->next;
        }
		// pre is NULL means that Nth Node is the head,remove head returns next node 
        if (pre == NULL) return nex;
        pre->next = nex;
        return ret;
    }
}; // 8ms

// Reference pezy
// (https://github.com/pezy/LeetCode/tree/master/053.%20Remove%20Nth%20Node%20from%20End%20of%20List)
// Another Solution that use less space
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode **del = &head;
        ListNode *indicator = head;
        for (int i = 0; i < n; ++i)
            indicator = indicator->next;
        while (indicator != NULL) {
            del = &((*del)->next);
            indicator = indicator->next;
        }
        *del = (*del)->next;
        return head;
    }
}; // 9ms