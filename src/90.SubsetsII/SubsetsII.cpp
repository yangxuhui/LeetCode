// Source: https://leetcode.com/problems/subsets-ii/
// 2015/5/29

// My Solution
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        sort(nums.begin(), nums.end());
        int cnt = 1;
        while (cnt <= nums.size()) {
            vector<int> vec_helper;
            for (int i = 0; i < cnt; ++i)
                vec_helper.push_back(nums[i]);
            ret.push_back(vec_helper);
            int pos = next(vec_helper, nums);
            while (pos != -1) {
                int ix = 0;
                for (int i = 0; i < nums.size(); ++i)
                    if (vec_helper[pos] < nums[i]) {
                        ix = i;
                        break;
                    }
                for (int i = pos; i < vec_helper.size(); ++i, ++ix)
                    vec_helper[i] = nums[ix];
                ret.push_back(vec_helper);
                pos = next(vec_helper, nums);
            }
            ++cnt;
        }
        return ret;
    }
private:
    int next(vector<int> vec1, vector<int>& vec2) {
        for (int i = vec1.size()-1, j = vec2.size()-1; i >= 0; --i, --j)
            if (vec1[i] < vec2[j]) return i;
        return -1;
    }
}; // 12ms

// Reference pezy
// https://github.com/pezy/LeetCode/tree/master/071.%20Subsets%20II
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret{{}};
        for (size_t i = 0, b = 0, e = 0; i < nums.size(); ++i) 
            for (b = i && nums[i] == nums[i-1] ? e : 0, e = ret.size(); b < e; ++b) 
                ret.insert(ret.end(), ret[b])->push_back(nums[i]);
        return ret;
    }
}; // 8ms