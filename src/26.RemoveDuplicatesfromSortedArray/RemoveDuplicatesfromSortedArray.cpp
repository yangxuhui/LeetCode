// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// 2015/4/26

// Reference pezy
// (https://github.com/pezy/LeetCode/tree/master/024.%20Remove%20Duplicates%20from%20Sorted%20Array)
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2) return n;
        int size = 1;
        for (int i = 1; i != n; ++i)
            if (A[i] != A[i-1])
                A[size++] = A[i];
        return size;
    }
}; // 43ms

// My Soulution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (i < nums.size()-1 && nums[i] == nums[i+1]) ++i;
            nums[len++] = nums[i];
        }
        return len;
    }
}; // 32ms