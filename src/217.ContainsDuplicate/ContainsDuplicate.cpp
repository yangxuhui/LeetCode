// Source: https://leetcode.com/problems/contains-duplicate/
// 2015/7/2

// My Solution
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return set<int>(nums.cbegin(), nums.cend()).size() < nums.size();
    }
}; // 48ms