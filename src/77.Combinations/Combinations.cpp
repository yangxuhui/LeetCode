// Source: https://leetcode.com/problems/combinations/
// 2015/5/21

// My Solution
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k > n) return vector<vector<int>>();
        vector<vector<int>> ret;
        vector<int> vec_helper;
        int i = 1;
        while (i <= k) 
            vec_helper.push_back(i++);
        ret.push_back(vec_helper);
        while (hasNext(vec_helper, n)) {
            i = vec_helper.size() - 1;
            while (i >= 0 && vec_helper[i] >= n-k+i+1) --i;
            vec_helper[i] += 1;
            while (i < vec_helper.size()-1) {
                vec_helper[i+1] = vec_helper[i] + 1;
                ++i;
            }
            ret.push_back(vec_helper);
        }
        return ret;
    }
private:
    bool hasNext(vector<int> vec, int n) {
        for (int i = vec.size()-1; i >= 0; --i, --n) 
            if (vec[i] < n) return true;
        return false;
    }
}; // 8ms