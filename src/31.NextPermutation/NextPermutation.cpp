// Source: https://leetcode.com/problems/next-permutation/
// 2015/7/7

// My Solution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i-1]) --i;
        if (i == 0) sort(nums.begin(), nums.end());
        else {
            int ix = i, dis = INT_MAX;
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] > nums[i-1] && (nums[j] - nums[i-1] < dis)) {
                    ix = j; dis = nums[j] - nums[i-1];
                }
            }
            std::swap(nums[i-1], nums[ix]);
            sort(nums.begin()+i, nums.end());
        }
    }
}; // 12ms

// Reference https://leetcode.com/discuss/24515/9-lines-of-c-code-with-comments
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int i = nums.size() - 2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i+1]) break;
        }
        reverse(begin(nums)+i+1, end(nums));
        if (i == -1) return;
        auto it = upper_bound(begin(nums)+i+1, end(nums), nums[i]);
        swap(nums[i], *it);
    }
}; // 12ms
