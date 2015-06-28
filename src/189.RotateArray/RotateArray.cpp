// Source: https://leetcode.com/problems/rotate-array/
// 2015/6/28

// My Solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0) return;
        k = k % nums.size();
        if (k == 0 || nums.size() == k)
            return;
        reverse(nums, 0, nums.size() - k - 1);
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }
private:
    void reverse(vector<int> &nums, int begin, int end) {
        for (; begin < end; ++begin, --end)
            std::swap(nums[begin], nums[end]);
    }
}; // 24ms