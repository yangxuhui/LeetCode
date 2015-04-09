// Source: https://leetcode.com/problems/container-with-most-water/
// 2015/4/9

// Reference the solution of haeol
// (https://github.com/haoel/leetcode/blob/master/algorithms/containerWithMostWater/containerWithMostWater.cpp)
class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int area = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
            max_area = (area > max_area) ? area : max_area;
            if (height[left] < height[right]) {
                do {
                    ++left;
                } while (left < right && height[left-1] >= height[left]);
            } else {
                do {
                    --right;
                } while (left < right && height[right+1] >= height[right]);
            }
        }
        return max_area;
    }
}; // 32ms