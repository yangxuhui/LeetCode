// Source: https://leetcode.com/problems/add-two-numbers/
// 2015/3/31

/* Notice that sum and m are long long 
 * (This bug takes me a whole morning!!!)
 * This solution is bad
 */
//class Solution {
//public:
//    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//        long long sum = 0; 
//        long long m = 1;
//        ListNode *ret, *p;
//        bool flag = true;
//        while (l1) {
//            if (flag) flag = false;
//            else {
//                m = m * 10;
//            }
//            sum = sum + l1->val * m;
//            std::cout << sum << std::endl;
//            l1 = l1->next;
//        }
//        flag = true; m = 1;
//        while (l2) {
//            if (flag) flag = false;
//            else {
//                m = m * 10;
//            }
//            sum = sum + l2->val * m;
//            std::cout << sum << "---" << std::endl;
//            l2 = l2->next;
//        }
//        if (sum) {
//            p = new ListNode(sum % 10);
//            ret = p;
//            sum = sum / 10;
//        } else {
//            ret = new ListNode(sum);
//        }
//        while (sum) {
//            p->next = new ListNode(sum % 10);
//            p = p->next;
//            sum = sum / 10;
//        }
//        return ret;
//    }
//}; // 65ms

/* Thanks to haoel()
 * This solution is easy to think,
 * but there are some point to notice
 */
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = NULL, **p = &ret;
        int sum = 0, carry = 0;
        while (l1 || l2) {
            int digL1 = 0, digL2 = 0;
            if (l1) digL1 = l1->val;
            if (l2) digL2 = l2->val;
            sum = digL1 + digL2 + carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            *p = node;
            p = &(node->next);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) {
            *p = new ListNode(carry);
        }
        return ret;
    }
};
/** 
 * This takse 55ms in the best case, but sometimes 68ms,
 * thus do not be too sure to LeetCode
 */ 

