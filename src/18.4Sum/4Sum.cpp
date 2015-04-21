// Source: https://leetcode.com/problems/4sum/
// 2015/4/21

// My Solution
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        int sz = num.size();
        if (sz < 4) return ret;
        sort(num.begin(), num.end());
        for (int fst = 0; fst < sz - 3; ++fst) {
            if (fst > 0 && num[fst] == num[fst-1]) continue;
            int scd = fst + 1;
            for (; scd < sz - 2; ++scd) {
                if (scd > fst + 1 && num[scd] == num[scd-1]) continue;
                int trd = scd + 1;
                int fth = sz -1;
                while (trd < fth) {
                    int sum = num[fst] + num[scd] + num[trd] + num[fth];
                    if (sum < target) {
                        while (trd < sz - 1 && num[trd] == num[trd+1]) ++trd;
                        ++trd;
                    } else if (sum == target) {
                        vector<int> tmp;
                        tmp.push_back(num[fst]);
                        tmp.push_back(num[scd]);
                        tmp.push_back(num[trd]);
                        tmp.push_back(num[fth]);
                        ret.push_back(tmp);
                        while (trd < sz - 1 && num[trd] == num[trd+1]) ++trd;
                        while (fth > 0 && num[fth] == num[fth-1]) --fth;
                        ++trd;
                        --fth;
                    } else {
                        while (fth > 0 && num[fth] == num[fth-1]) --fth;
                        --fth;
                    }
                }
            }
        }
        return ret;
    }
}; // 153ms