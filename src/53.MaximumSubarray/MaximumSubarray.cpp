// Source: https://leetcode.com/problems/maximum-subarray/
// 2015/5/9

// My Solution 
// Solution 1: Divde and Conquer(Recursion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        return max_sum(nums, 0, nums.size() - 1);
    }
private:
    int max_cross_sum(vector<int>& nums, int low, int mid, int high) {
        int left_sum = INT_MIN, sum = 0;
        for (int i = mid; i >= low; --i) {
            sum = sum + nums[i];
            if (sum > left_sum)
                left_sum = sum;
        }
        int right_sum = INT_MIN;
        sum = 0;
        for (int j = mid + 1; j <= high; ++j) {
            sum = sum + nums[j];
            if (sum > right_sum)
                right_sum = sum;
        }
        return left_sum + right_sum;
    }
    int max_sum(vector<int>& nums, int low, int high) {
        if (low == high)
            return nums[low];
        else {
            int mid = (low + high) / 2;
            int left_sum = max_sum(nums, low, mid);
            int right_sum = max_sum(nums, mid + 1, high);
            int cross_sum = max_cross_sum(nums, low, mid, high);
            if (left_sum >= right_sum && left_sum >= cross_sum)
                return left_sum;
            else if (right_sum >= left_sum && right_sum >= cross_sum)
                return right_sum;
            else return cross_sum;
        }
    }
}; // 20ms

// Solution2:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int max_sum = nums[0];
        for (int i = 1, sum_contain_i = nums[0]; i != nums.size(); ++i) {
            sum_contain_i = sum_contain_i > 0 ? sum_contain_i + nums[i] : nums[i];
            if (sum_contain_i > max_sum)
                max_sum = sum_contain_i;
        }
        return max_sum;
    }
}; // 14ms