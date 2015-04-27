// Source: https://leetcode.com/problems/remove-element/
// 2015/4/27

// My Reference
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int len = 0;
        for (int i = 0; i < n; ++i)
            if (A[i] != elem)
                A[len++] = A[i];
        return len;
    }
}; //7ms