// Source: https://leetcode.com/problems/search-in-rotated-sorted-array/
// 2015/4/30

// My Solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	// if the array is sorted, binary search
        if (nums[0] < nums[nums.size()-1]) return binary_search(nums, 0, nums.size() - 1, target);
        int low = 0;
        // find the rotated piovt
        // beacuse we exclude the case which the array is sorted, so there must be a rotated piovt
        while (low < nums.size()-1 && nums[low] != target && nums[low] < nums[low+1]) ++low;
        // find target in the first sorted array
        if (nums[low] == target) return low;
        else return binary_search(nums,low+1, nums.size()-1, target);
    }
private:
    int binary_search(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
}; // 7ms