// Source: https://leetcode.com/problems/sort-colors/
// 2015/5/21

// My Solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for (int i = 0; i < nums.size(); ++i)
            count[nums[i]] += 1;
        for (int i = 1; i < count.size(); ++i)
            count[i] = count[i] + count[i-1];
        vector<int> vec_helper(nums.size(), 0);
        for (int i = nums.size()-1; i >= 0; --i) {
            vec_helper[count[nums[i]] - 1] = nums[i];
            --count[nums[i]];
        }
        nums = std::move(vec_helper);
    }
}; // 4ms