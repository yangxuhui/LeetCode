// Source: https://leetcode.com/problems/search-for-a-range/
// 2015/4/30

// My Solution 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = 0;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                pos = mid;
                break;
            }
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        if (low > high) return {-1, -1};
        else {
            int beg = pos;
            while (beg >=0 && nums[beg] == nums[pos]) --beg;
            int end = pos;
            while (end < nums.size() && nums[end] == nums[pos]) ++end;
            return {beg+1, end-1};
        }
    }
}; // 15ms