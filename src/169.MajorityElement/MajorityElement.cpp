// Source: https://leetcode.com/problems/majority-element/
// 2015/6/23

// My Solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (auto elem : nums)
            ++m[elem];
        for (auto elem : m)
            if (elem.second > nums.size() / 2)
                return elem.first;
    }
}; // 32ms

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int majElem = 0;
        for (int i = 1, cnt = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                ++cnt;
                if (cnt > nums.size() / 2) return nums[i];
            }
            else cnt = 1;
        }
        return nums[0];
    }
}; // 40ms