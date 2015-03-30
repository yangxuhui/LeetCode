// Source: https://leetcode.com/problems/two-sum/
// 2015/3/30

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        vector<int> tmp = numbers;
        int a = 0, b = 0;
        sort(tmp.begin(), tmp.end());
        auto sz = numbers.size();
        bool flag = false;
        for (vector<int>::size_type ix = 0; ix != sz - 1; ++ix) {
            auto ix2 = ix + 1;
            while (ix2 != sz) {
                if ((tmp[ix] + tmp[ix2]) >= target) {
                    if ((tmp[ix] + tmp[ix2]) == target) {
                        flag = true;
                        a = tmp[ix];
                        b = tmp[ix2];
                    }
                    break;
                }
                ++ix2;
            }
            if (flag) break;
        }
        int ix = 1;
        for (auto elem : numbers) {
            if (elem == a) ret.push_back(ix);
            else if (elem == b) ret.push_back(ix);
            if (ret.size() == 2) break;
            ++ix;
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};

